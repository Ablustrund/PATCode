#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int cmax, n, sp, m, u, v, w, verWeight[510], dis[510];
bool tag[510];
struct node
{
    int v, timee;
    node(int _v, int _timee) { v = _v; timee = _timee;}
};
vector<node> graph[510];
vector<int> pre[510];
void dijkstra(int u)
{
    fill(dis, dis + 510, inf);
    fill(tag, tag + 510, false);
    dis[u] = 0;
    for (int i = 0; i < n + 1; i++)
    {
        int k = -1, minn = inf;
        for (int j = 0; j < n + 1; j++)
        {
            if(!tag[j] && minn > dis[j])
            {
                minn = dis[j];
                k = j;
            }
        }
        if(k == -1) return;
        tag[k] = true;
        for (int j = 0; j < graph[k].size(); j++)
        {
            if(!tag[graph[k][j].v] && dis[graph[k][j].v] > dis[k] + graph[k][j].timee)
            {
                dis[graph[k][j].v] = dis[k] + graph[k][j].timee;
                pre[graph[k][j].v].clear();
                pre[graph[k][j].v].push_back(k);
            }
            else if(!tag[graph[k][j].v] && dis[graph[k][j].v] == dis[k] + graph[k][j].timee) pre[graph[k][j].v].push_back(k);
        }
    }
}
vector<int> tempPath, res;
int mintakeback = inf, minsendto = inf;
void dfs(int u)
{
    tempPath.push_back(u);
    if(u == 0)
    {
        int tempsendto = 0, temptakeback = 0;
        for (int i = (int)tempPath.size() - 2; i >= 0; i--)
        {
            int id = tempPath[i];
            int tempNeed = cmax/2 - verWeight[id];
            if(tempNeed > 0)
            {
                if(temptakeback > tempNeed)
                {
                    temptakeback -= tempNeed;
                }
                else
                {
                    tempsendto += tempNeed - temptakeback;
                    temptakeback = 0;
                }
            }
            else if(tempNeed < 0)
            {
                temptakeback += 0 - (tempNeed);
            }
        }
        if(tempsendto < minsendto)
        {
            minsendto = tempsendto;
            mintakeback = temptakeback;
            res = tempPath;
        }
        else if(tempsendto == minsendto && temptakeback < mintakeback)
        {
            minsendto = tempsendto;
            mintakeback = temptakeback;
            res = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for (int i = 0; i < pre[u].size(); i++) dfs(pre[u][i]);
    tempPath.pop_back();
    return;
}
int main()
{
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &verWeight[i]);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        graph[u].push_back(node(v, w));
        graph[v].push_back(node(u, w));
    }
    dijkstra(0);
    dfs(sp);
    printf("%d ", minsendto);
    for (int i = (int)res.size()-1; i >= 0; i--)
    {
        if(i+1 == res.size()) printf("%d", res[i]);
        else printf("->%d", res[i]);
    }
    printf(" %d\n", mintakeback);
    return 0;
}
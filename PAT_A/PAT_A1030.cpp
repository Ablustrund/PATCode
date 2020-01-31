#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int n, m, s, d, u, v, dis, cost, diss[510], costs[510];
bool visited[510];
vector<int> pre[510];
struct node
{
    int v, dis, cost;
    node(int _v, int _dis, int _cost){v = _v; dis = _dis; cost = _cost;}
};
vector<node> graph[510];
void dijkstra(int uu, int dd)
{
    fill(visited, visited + 510, false);
    fill(diss, diss + 510, inf);
    fill(costs, costs + 510, inf);
    diss[uu] = 0;
    costs[uu] = 0;
    for (int i = 0; i < n; i++)
    {
        int k, minn = inf;
        for(int j = 0; j < n; j++)
        {
            if(diss[j] < minn && !visited[j])
            {
                k = j;
                minn = diss[j];
            }
        }
        visited[k] = true;
        pre[k].push_back(k);
        if(k == dd) return;
        for (int j = 0; j < graph[k].size(); j++)
        {
            int vv = graph[k][j].v;
            if(visited[vv] == false)
            {
                if(diss[vv] > diss[k] + graph[k][j].dis)
                {
                    diss[vv] = diss[k] + graph[k][j].dis;
                    costs[vv] = costs[k] + graph[k][j].cost;
                    pre[vv] = pre[k];
                    //pre[vv].push_back(k);
                }
                else if(diss[vv] == diss[k] + graph[k][j].dis && costs[vv] > costs[k] + graph[k][j].cost)
                {
                    costs[vv] = costs[k] + graph[k][j].cost;
                    pre[vv] = pre[k];
                    //pre[vv].push_back(k);
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d%d", &u, &v, &dis, &cost);
        graph[u].push_back(node(v, dis, cost));
        graph[v].push_back(node(u, dis, cost));
    }
    dijkstra(s, d);
    for (int i = 0; i < pre[d].size(); i++) if(i == 0) printf("%d", pre[d][i]); else printf(" %d", pre[d][i]);
    printf(" %d %d\n", diss[d], costs[d]);
    
    return 0;
}
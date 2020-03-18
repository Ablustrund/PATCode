#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
struct edge
{
    int v, dis;
    edge(int _v, int _dis) {v = _v; dis = _dis; }
};
vector<struct edge>graph[2010];
int n, m, k, ds, temp1, temp2, temp3, d[2010], vis[2010], resPos;
double resMin = -1, resSum = inf;
string s1, s2;
int getIt(string str)
{
    if(str[0] == 'G') return n + stoi(str.substr(1));
    else return stoi(str);
}
void dijkstra(int u)
{
    fill(vis, vis + 2010, 0);
    fill(d, d + 2010, inf);
    d[u] = 0;
    for(int i = 0; i < n + m; i++)
    {
        int minn = inf, v = -1;
        for (int j = 1; j <= n + m; j++)
        {
            if(!vis[j] && d[j] < minn)
            {
                minn = d[j];
                v = j;
            }
        }
        vis[v] = 1;
        if(v == -1) return;
        for (int j = 0; j < graph[v].size(); j++)
        {
            if(!vis[graph[v][j].v] && d[graph[v][j].v] > d[v] + graph[v][j].dis)
            {
                d[graph[v][j].v] = d[v] + graph[v][j].dis;
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    for (int i = 0; i < k; i++)
    {
        cin >> s1 >> s2 >> temp3;
        temp1 = getIt(s1);
        temp2 = getIt(s2);
        graph[temp1].push_back(edge(temp2, temp3));
        graph[temp2].push_back(edge(temp1, temp3));
    }
    for(int i = n + 1; i <= n + m; i++)
    {
        dijkstra(i);
        double tempMin = inf, tempSum = 0.0;
        for (int j = 1; j <= n; j++)
        {
            if(d[j] > ds)
            {
                tempMin = -1;
                break;
            }
            if(tempMin > d[j]) tempMin = d[j];
            tempSum += d[j];
        }
        if(tempMin == -1) continue;
        if(resMin < tempMin)
        {
            resMin = tempMin;
            resSum = tempSum;
            resPos = i;
        }
        if(resMin == tempMin && resSum > tempSum)
        {
            resSum = tempSum;
            resPos = i;
        }
    }
    if(resMin == -1) printf("No Solution\n");
    else printf("G%d\n%.1f %.1f\n", resPos - n, resMin, resSum / n);
    return 0;
}
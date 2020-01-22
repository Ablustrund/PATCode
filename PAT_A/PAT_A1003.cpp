#include <bits/stdc++.h>
using namespace std;
int N, M, C1, C2, nodeCost[510], dis[510], resCost[510], numsOfSP[510], temp1, temp2, temp3;
bool flags[510] = {false};
struct node
{
    int xx, values;
    node(int _xx, int _values){xx = _xx; values = _values;}
};
vector<node> graph[510];
void dj(int beginNode)
{
    fill(dis, dis + 510, 1000000000);
    fill(resCost, resCost + 510, 0);
    dis[beginNode] = 0; numsOfSP[beginNode] = 1;
    for (int i = 0; i < N; i++)
    {
        int k = 0, minn = 1000000000;
        for (int j = 0; j < N; j++)
            if(flags[j] == false && minn > dis[j])
            {
                k = j;
                minn = dis[j];
            }
        flags[k] = true;
        resCost[k] += nodeCost[k];
        for (int j = 0; j < graph[k].size(); j++)
        {
            if(flags[graph[k][j].xx] == true) continue;
            if(dis[graph[k][j].xx] > dis[k] + graph[k][j].values)
            {
                dis[graph[k][j].xx] = dis[k] + graph[k][j].values;
                resCost[graph[k][j].xx] = resCost[k];
                numsOfSP[graph[k][j].xx] = numsOfSP[k];
            }
            else if(dis[graph[k][j].xx] == dis[k] + graph[k][j].values)
            {
                if(resCost[graph[k][j].xx] < resCost[k]) resCost[graph[k][j].xx] = resCost[k];
                numsOfSP[graph[k][j].xx] += numsOfSP[k];
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    for (int i = 0; i < N; i++) scanf("%d", &nodeCost[i]);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &temp1, &temp2, &temp3);
        graph[temp1].push_back(node(temp2, temp3));
        graph[temp2].push_back(node(temp1, temp3));
    }
    dj(C1);
    printf("%d %d\n", numsOfSP[C2], resCost[C2]);
    return 0;
}
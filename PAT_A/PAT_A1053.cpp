#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    int weight;
    vector<int> child;
} node[110];
int n, m, s;
int path[110];

bool cmp(int a, int b)
{
    return node[a].weight > node[b].weight;
}
void dfs(int index, int nodeNum, int weights)
{
    if (weights > s) return ;
    if(weights == s)
    {
        if(node[index].child.size() != 0) return;
        for (int i = 0; i < nodeNum; i++)
        {
            printf("%d", node[path[i]].weight);
            if(i < nodeNum - 1) printf(" ");
            else printf("\n");
        }
        return;
    }
    for (int i = 0; i < node[index].child.size(); i++)
    {
        int tempChild = node[index].child[i];
        path[nodeNum] = tempChild;
        dfs(tempChild, nodeNum + 1, weights + node[tempChild].weight);
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &node[i].weight);
    }
    int id, k, child;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            node[id].child.push_back(child);
        }
        sort(node[id].child.begin(), node[id].child.end(), cmp);
    }
    path[0] = 0;
    dfs(0, 1, node[0].weight);
    return 0;
}
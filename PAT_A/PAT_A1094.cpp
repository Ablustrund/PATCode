#include <bits/stdc++.h>
using namespace std;
int n, m, tempID, k, tempC, maxCount = -1, resLevel, counts[110];
vector<int> tree[110];
void dfs(int u, int level)
{
    counts[level]++;
    for(int i = 0; i < tree[u].size(); i++)
    {
        dfs(tree[u][i], level + 1);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &tempID, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &tempC);
            tree[tempID].push_back(tempC);
        }
    }
    fill(counts, counts + 110, 0);
    dfs(1, 1);
    for (int i = 1; i < 110; i++)
    {
        if(counts[i] > maxCount)
        {
            maxCount = counts[i];
            resLevel = i;
        }
    }
    printf("%d %d\n", maxCount, resLevel);
    return 0;
}
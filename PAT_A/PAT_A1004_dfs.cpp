#include <bits/stdc++.h>
using namespace std;
int n, m, tempRoot, K, tempChild, maxLevel = -1;
vector<vector<int>> trees(110);
vector<int> levelCounts(110, 0);
void dfs(int node, int depth)
{
    if(trees[node].size() == 0)
    {
        levelCounts[depth]++;
        if(maxLevel < depth) maxLevel = depth;
        return ;
    }
    for (int i = 0; i < trees[node].size(); i++) dfs(trees[node][i], depth+1);
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &tempRoot, &K);
        for (int j = 0; j < K; j++)
        {
            scanf("%d", &tempChild);
            trees[tempRoot].push_back(tempChild);
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= maxLevel; i++) if(i == 0) printf("%d", levelCounts[i]); else printf(" %d", levelCounts[i]);
    printf("\n");
}

#include <bits/stdc++.h>
using namespace std;
int n, m, k, tempi, tempj, res;
vector<int> graph[1010];
bool tags[1010];
void dfs(int u)
{
    if(tags[u] == true) return ;
    tags[u] = true;
    for (int i = 0; i < graph[u].size(); i++)
    {
        if(tags[graph[u][i]] == false) dfs(graph[u][i]);
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &tempi, &tempj);
        graph[tempi].push_back(tempj);
        graph[tempj].push_back(tempi);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &tempi);
        fill(tags, tags + 1010, false);
        res = 0;
        tags[tempi] = true;
        for (int j = 1; j <= n; j++)
        {
            if(tags[j] == false)
            {
                res++;
                dfs(j);
            }
        }
        printf("%d\n", res - 1);
    }
        return 0;
}
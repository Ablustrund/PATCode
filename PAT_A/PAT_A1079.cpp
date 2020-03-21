#include <bits/stdc++.h>
using namespace std;
int n, k, temp;
double p, r, res = 0;
bool isRetailer[100010], visited[100010];
double batchs[100010];
vector<int> trees[100010];
void dfs(int u, int level)
{
    if(visited[u]) return;
    visited[u] = true;
    if(isRetailer[u])
    {
        res += batchs[u] * p * pow(r, level);
    }
    for (int i = 0; i < trees[u].size(); i++)
    {
        if(!visited[trees[u][i]]) dfs(trees[u][i], level + 1);
    }
    return;
}
int main()
{
    fill(isRetailer, isRetailer + 100010, false);
    fill(visited, visited + 100010, false);
    scanf("%d%lf%lf", &n, &p, &r);
    r = 1 + r * 0.01;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (k == 0)
        {
            isRetailer[i] = true;
            scanf("%lf", &batchs[i]);
        }
        else
        {
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &temp);
                trees[i].push_back(temp);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f\n", res);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, u, v, maxx = -1, tempMax = -1, k = 0;
vector<int> graph[10010], res;
set<int> sets;
bool judgeTag[10010] = {false};
void dfs(int u, int len, int func)
{
    judgeTag[u] = true;
    if (func == 0 && tempMax < len)
        tempMax = len;
    else if (func == 1 && len == tempMax)
    {
        res.push_back(u);
        sets.insert(u);
    }
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (!judgeTag[graph[u][i]])
        {
            if(func == 0) dfs(graph[u][i], len + 1, 0);
            else if(func == 1) dfs(graph[u][i], len + 1, 1);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!judgeTag[i])
        {
            dfs(i, 0, 0);
            k++;
        }
    if (k != 1)
    {
        printf("Error: %d components\n", k);
        return 0;
    }
    tempMax = -1;
    fill(judgeTag, judgeTag + 10010, false);
    dfs(1, 0, 0);
    fill(judgeTag, judgeTag + 10010, false);
    dfs(1, 0, 1);
    tempMax = -1;
    fill(judgeTag, judgeTag + 10010, false);
    dfs(res[0], 0, 0);
    fill(judgeTag, judgeTag + 10010, false);
    dfs(res[0], 0, 1);
    for (auto i = sets.begin(); i != sets.end(); i++)
        printf("%d\n", *i);
    return 0;
}
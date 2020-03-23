#include <bits/stdc++.h>
using namespace std;
int n, temp, root, deepLevel = -1, counts = 0;
double p, r;
vector<int> tree[100010];
void dfs(int u, int level)
{
    if(level > deepLevel)
    {
        deepLevel = level;
        counts = 0;
    }
    if(deepLevel == level) counts++;
    if(tree[u].size() == 0) return;
    for (int i = 0; i < tree[u].size(); i++)
    {
        dfs(tree[u][i], level + 1);
    }
        return;
}
int main()
{
    scanf("%d%lf%lf", &n, &p, &r);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if(temp == -1)
        {
            root = i;
            continue;
        }
        tree[temp].push_back(i);
    }
    dfs(root, 0);
    printf("%.2f %d\n", pow(1 + 0.01 * r, deepLevel) * p, counts);
    return 0;
}
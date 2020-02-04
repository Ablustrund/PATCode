#include <bits/stdc++.h>
using namespace std;
vector<int> tree[110], temp;
vector<vector<int>> res;
int n, m, s, u, k, v, weights[110];
bool cmp(const int &a, const int &b) { return weights[a] > weights[b]; }
void dfs(int u, int weight)
{
    weight += weights[u];
    if(weight > s || (weight == s && tree[u].size() != 0)) return;
    temp.push_back(weights[u]);
    if(weight == s && tree[u].size() == 0)
    {
        res.push_back(temp);
        weight -= weights[u];
        temp.erase(temp.end() - 1);
        return;
    }
    for (int i = 0; i < tree[u].size(); i++) dfs(tree[u][i], weight);
    weight -= weights[u];
    temp.erase(temp.end() - 1);
    return;
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; i++) scanf("%d", &weights[i]);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &v);
            tree[u].push_back(v);
        }
        sort(tree[u].begin(), tree[u].end(), cmp);
    }
    dfs(0, 0);
    for(auto&i:res)
    {
        for (int j = 0; j < i.size(); j++)
        {
            if( j == 0) printf("%d", i[j]);
            else printf(" %d", i[j]);
        }
        printf("\n");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, t1, t2, tree[110][2], glo = 0;
int node[110], t[110];
void dfs(int u)
{
    if(tree[u][0] != -1) dfs(tree[u][0]);
    node[u] = t[glo++];
    if(tree[u][1] != -1) dfs(tree[u][1]); 
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &tree[i][0], &tree[i][1]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
    }
    sort(t, t + n);
    dfs(0);
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        if(tmp == 0) printf("%d", node[tmp]);
        else printf(" %d", node[tmp]);
        if(tree[tmp][0] != -1) q.push(tree[tmp][0]);
        if(tree[tmp][1] != -1) q.push(tree[tmp][1]);
    }
    printf("\n");
    return 0;
}
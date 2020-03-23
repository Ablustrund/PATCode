#include <bits/stdc++.h>
using namespace std;
int m, n, l, t, res, blocks[60][1286][128];
int direct[6][3] = {{0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}};
bool vis[60][1286][128];
struct node
{
    int x, y, z;
};
int bfs(int x, int y, int z)
{
    int tmpc = 0;
    node tmp;
    tmp.x = x, tmp.y = y, tmp.z = z;
    queue<node> q;
    q.push(tmp);
    while(!q.empty())
    {
        node tmpfront = q.front();
        tmpc++;
        q.pop();
        for(int i = 0; i < 6; i++)
        {
            int tmpx = tmpfront.x + direct[i][0];
            int tmpy = tmpfront.y + direct[i][1];
            int tmpz = tmpfront.z + direct[i][2];
            if(tmpx < 0 || tmpx >= l || tmpy < 0 || tmpy >= m || tmpz < 0 || tmpz >= n) continue;
            if(blocks[tmpx][tmpy][tmpz] == 1 && !vis[tmpx][tmpy][tmpz])
            {
                tmp.x = tmpx, tmp.y = tmpy, tmp.z = tmpz;
                vis[tmpx][tmpy][tmpz] = true;
                q.push(tmp);
            }
        }
    }

    if(tmpc >= t) return tmpc;
    else return 0;
}
int main()
{
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int i = 0; i < l; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++) scanf("%d", &blocks[i][j][k]);
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if(!vis[i][j][k] && blocks[i][j][k] == 1)
                {
                    vis[i][j][k] = true;
                    res += bfs(i, j, k);
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
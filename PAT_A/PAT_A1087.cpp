#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int n, k, h, temp3, happy[20010], d[20010], resCount;
bool vis[20010];
int resCost = 0, resH = 0, resHM = 0;
string beg, temp, temp2;
struct node
{
    int v, d;
    node(int _v, int _d)
    {
        v = _v;
        d = _d;
    }
};
vector<struct node>graph[20010];
vector<int> pre[20010], tempPath, resPath;
string inttostr(int num)
{
    string str = "AAA";
    str[0] = 'A' + num / (26 * 26);
    str[1] = 'A' + num % (26 * 26) / 26;
    str[2] = 'A' + num % 26;
    return str;
}
void dijkstra(int u)
{
    fill(vis, vis + 20010, false);
    fill(d, d + 20010, inf);
    d[u] = 0;
    for (int i = 0; i < n; i++)
    {
        int minn = inf, mm = 0;
        for (int j = 0; j < 20010; j++)
        {
            if(!vis[j] && d[j] < minn)
            {
                minn = d[j];
                mm = j;
            }
        }
        vis[mm] = true;
        for (int j = 0; j < graph[mm].size(); j++)
        {
            if(!vis[graph[mm][j].v])
            {
                if(graph[mm][j].d + d[mm] < d[graph[mm][j].v])
                {
                    d[graph[mm][j].v] = graph[mm][j].d + d[mm];
                    pre[graph[mm][j].v].clear();
                    pre[graph[mm][j].v].push_back(mm);
                }
                else if(graph[mm][j].d + d[mm] == d[graph[mm][j].v])
                {
                    pre[graph[mm][j].v].push_back(mm);
                }
            }
        }
    }
}
int strtoint(string str)
{
    return (str[0] - 'A') * 26 * 26 + (str[1] - 'A') * 26 + str[2] - 'A';
}
void dfs(int u)
{
    // printf("%s\n", inttostr(u).c_str());
    if(u == strtoint(beg))
    {
        tempPath.push_back(u);
        int tempH = 0, tempHM = 0;
        for (int i = 0; i < tempPath.size(); i++)
        {
            tempH += happy[tempPath[i]];
        }
        tempHM = tempH / (tempPath.size() - 1);
        resCount++;
        if(tempH > resH)
        {
            resH = tempH;
            resHM = tempHM;
            resPath = tempPath;
        }
        else if(tempH == resH && tempHM > resHM)
        {
            resHM = tempHM;
            resPath = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(u);
    for (int i = 0; i < pre[u].size(); i++)
    {
        dfs(pre[u][i]);
    }
    tempPath.pop_back();
    return;
}
int main()
{
    cin >> n >> k >> beg;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp >> h;
        happy[strtoint(temp)] = h;
    }
    for(int i = 0; i < k; i++)
    {
        cin >> temp >> temp2 >> temp3;
        graph[strtoint(temp)].push_back(node(strtoint(temp2), temp3));
        graph[strtoint(temp2)].push_back(node(strtoint(temp), temp3));
    }
    dijkstra(strtoint(beg));
    resCost = d[strtoint("ROM")];
    dfs(strtoint("ROM"));
    printf("%d %d %d %d\n", resCount, resCost, resH, resHM);
    printf("%s", inttostr(resPath[resPath.size() - 1]).c_str());
    for (int i = resPath.size() - 2; i >= 0; i--)
    {
        printf("->%s", inttostr(resPath[i]).c_str());
    }
    printf("\n");
    return 0;
}
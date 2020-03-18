#include <bits/stdc++.h>
using namespace std;
int n, level, M, temp, visited[1010], nodeLevel[1010];
vector<int> graph[1010];
int main()
{
    scanf("%d%d", &n, &level);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &M);
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &temp);
            graph[temp].push_back(i);
        }
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &temp);
        int res = 0;
        fill(visited, visited + 1010, 0);
        fill(nodeLevel, nodeLevel + 1010, 0);
        queue<int> q;
        q.push(temp);
        visited[temp] = 1;
        while(!q.empty())
        {
            int nowNode = q.front();
            if(nodeLevel[nowNode] >= level) break;
            q.pop();
            for (int j = 0; j < graph[nowNode].size(); j++)
            {
                if(visited[graph[nowNode][j]] == 0)
                {
                    q.push(graph[nowNode][j]);
                    res++;
                    visited[graph[nowNode][j]] = 1;
                    nodeLevel[graph[nowNode][j]] = nodeLevel[nowNode] + 1;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
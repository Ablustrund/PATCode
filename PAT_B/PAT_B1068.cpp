#include <bits/stdc++.h>
using namespace std;

int m, n, tol, graph[1010][1010], resX, resY, resVal;
map<int, int> existDot;
bool uniqueFlag = false;
int main()
{
    scanf("%d%d%d", &m, &n, &tol);
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++) graph[i][j] = -1000000000;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &graph[i][j]);
            if(existDot.find(graph[i][j]) != existDot.end()) existDot[graph[i][j]]++;
            else existDot[graph[i][j]] = 1;
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int k = graph[i][j];
            if((existDot[k] == 1)&&abs(k-graph[i-1][j-1])>tol&&abs(k-graph[i-1][j])>tol&&abs(k-graph[i-1][j+1])>tol&&abs(k-graph[i][j-1])>tol&&abs(k-graph[i][j+1])>tol&&abs(k-graph[i+1][j-1])>tol&&abs(k-graph[i+1][j])>tol&&abs(k-graph[i+1][j+1])>tol)
            {
                if(uniqueFlag)
                {
                    printf("Not Unique\n");
                    return 0;
                }
                resX = i;
                resY = j;
                resVal = k;
                uniqueFlag = true;
            }
        }
    }
    if(uniqueFlag) printf("(%d, %d): %d\n", resY, resX, resVal);
    else printf("Not Exist\n");
    return 0;
}
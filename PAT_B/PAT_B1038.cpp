#include <bits/stdc++.h>
using namespace std;
int n, tempScore;
int scores[110];
int main()
{
    fill(scores, scores+110, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempScore);
        scores[tempScore]++;
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tempScore);
        if(i == 0) printf("%d", scores[tempScore]);
        else printf(" %d", scores[tempScore]);
    }
    return 0;
}
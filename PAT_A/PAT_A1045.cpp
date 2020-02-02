#include <bits/stdc++.h>
using namespace std;
int n, m, l, temp, revOrder[210], input[10010], maxx = 0, dp[10010];
set<int> sets;
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &temp);
        sets.insert(temp);
        revOrder[temp] = i;
    }
    scanf("%d", &l);
    for(int i = 0; i < l; i++) scanf("%d", &input[i]);
    for(int i = 0; i < l; i++)
    {
        if(sets.find(input[i]) == sets.end()) continue;
        dp[i] = 1;
        for (int j = 0; j < i; j++) if(revOrder[input[j]] <= revOrder[input[i]] && dp[j]+1 > dp[i]) dp[i] = dp[j] + 1;
        maxx = max(maxx, dp[i]);
    }
    printf("%d\n", maxx);
    return 0;
}
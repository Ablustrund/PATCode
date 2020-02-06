#include <bits/stdc++.h>
using namespace std;
int n, m, i;
int coins[10010], dp[110];
bool path[10010][110];
vector<int> res;
bool cmp(const int a, const int b) { return a > b; }
int main()
{
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) scanf("%d", &coins[i]);
    sort(coins, coins + n, cmp);
    for (i = 0; i < n; i++)
    {
        for (int j = m; j >= coins[i]; j--)
        {
            if(dp[j - coins[i]] + coins[i] >= dp[j])
            {
                path[i][j] = true;
                dp[j] = dp[j - coins[i]] + coins[i];
            }
        }
    }
    if(dp[m] != m)
    {
        printf("No Solution\n");
        return 0;
    }
    else
    {
        i = n - 1;
        while(1)
        {
            if(path[i][m])
            {
                res.push_back(coins[i]);
                m -= coins[i];
            }
            i--;
            if(m == 0 || i == 0) break;
        }
    }
    for (i = 0; i < res.size(); i++)
    {
        if(i == 0) printf("%d", res[i]);
        else printf(" %d", res[i]);
    }
    printf("\n");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int K, seq[10010], dp[10010], maxx, beginPos, endPos, temp = 0;
int main()
{
    scanf("%d", &K);
    for (int i = 0; i < K; i++) scanf("%d", &seq[i]);
    dp[0] = seq[0];
    maxx = dp[0];
    for(int i = 1; i < K; i++)
    {
        if(seq[i] > dp[i-1] + seq[i]) dp[i] = seq[i];
        else dp[i] = dp[i-1] + seq[i];
        if(maxx < dp[i]) maxx = dp[i];
    }
    for(int i = 0; i < K; i++) if(dp[i] == maxx) {endPos = i; break;}
    for(int i = endPos; i >= 0; i--)
    {
        temp += seq[i];
        if(temp == maxx) beginPos = i;
    }
    if(maxx < 0) printf("0 %d %d\n", seq[0], seq[K - 1]);
    else printf("%d %d %d\n", maxx, seq[beginPos], seq[endPos]);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, m, temp, u, v, sums, oneToN[100010];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        oneToN[i] = sums;
        sums += temp;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        int temp1 = oneToN[max(u, v)] - oneToN[min(u, v)];
        int temp2 = sums - temp1;
        printf("%d\n", min(temp1, temp2));
    }
    return 0;
}
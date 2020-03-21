#include <bits/stdc++.h>
using namespace std;
long long int res, numts[110], dens[110];
int n;
long long int gcd(long long int a,long long int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld/%lld", &numts[i], &dens[i]);
    }
    long long int minC = dens[0];
    for(int i = 1; i < n; i++)
    {
        minC = minC * dens[i] / gcd(minC, dens[i]);
    }
    for (int i = 0; i < n; i++)
    {
        res += minC / dens[i] * numts[i];
    }
    long long int temp = gcd(abs(res), minC);
    res /= temp;
    minC /= temp;
    if(res == 0) printf("0\n");
    else if(minC == 1) printf("%lld\n", res);
    else if(abs(res) < minC) printf("%lld/%lld\n", res, minC);
    else printf("%lld %lld/%lld\n", res / minC, res - (res / minC) * minC, minC);
    return 0;
}
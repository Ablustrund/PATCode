#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int>> res;
int main()
{
    long long int n;
    scanf("%lld", &n);
    double bound = sqrt(n);
    long long int temp = n;
    for (long long int i = 2; i <= (int)bound + 1; i++)
    {
        if (n % i == 0)
        {
            long long int k = 0;
            while (n % i == 0)
            {
                n /= i;
                k++;
            }
            res.push_back(make_pair(i, k));
        }
    }
    if(n != 1) res.push_back(make_pair(n, 1));
    if(temp == n) printf("%d=%d\n", temp, temp);
    else
    {
        printf("%d=", temp);
        for(int i = 0; i < res.size(); i++)
        {
            if(i != 0) printf("*");
            if(res[i].second == 1) printf("%d", res[i].first);
            else printf("%d^%d", res[i].first, res[i].second);
        }
    }
    return 0;
}

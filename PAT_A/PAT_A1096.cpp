#include <bits/stdc++.h>
using namespace std;
long long int n;
vector<int> res, tmp;
int resL = -1;
int main()
{
    scanf("%lld", &n);
    double loop = sqrt(n);
    for (int i = 2; i < loop + 2; i++)
    {
        int tl = 0, tori = n, j = i;
        tmp.clear();
        while(tori % j == 0)
        {
            tmp.push_back(j);
            tori /= j;
            tl++;
            j++;
        }
        if(tl > resL)
        {
            resL = tl;
            res = tmp;
        }
    }
    if(resL == 0)
    {
        printf("1\n%lld\n", n);
        return 0;
    }
    printf("%d\n", resL);
    for (int i = 0; i < res.size(); i++)
    {
        if(i == 0) printf("%d", res[i]);
        else printf("*%d", res[i]);
    }
        return 0;
}
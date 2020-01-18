#include <bits/stdc++.h>
using namespace std;

int n, d, k, totalCount1 = 0, totalCount2 = 0, count1;
double e, tempE;
int main()
{
    scanf("%d%lf%d", &n, &e, &d);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        count1 = 0;
        for(int j = 0; j < k; j++)
        {
            scanf("%lf", &tempE);
            if(tempE < e) count1++;
        }
        if(count1 > k / 2)
        {
            if(k > d) totalCount2++;
            else totalCount1++;
        }
    }
    double out1 = totalCount1 * 100.0;
    double out2 = totalCount2 * 100.0;
    printf("%.1f%% %.1f%%\n", out1 / n, out2 / n);
    return 0;
}
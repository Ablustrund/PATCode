#include <bits/stdc++.h>
using namespace std;

int m, n, a, b, val, temp1;
int main()
{
    scanf("%d%d%d%d%d", &m, &n, &a, &b, &val);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &temp1);
            if(j == 0)
            {
                if(a <= temp1 && temp1 <= b) printf("%03d", val);
                else printf("%03d", temp1);
            }
            else
            {
                if(a <= temp1 && temp1 <= b) printf(" %03d", val);
                else printf(" %03d", temp1);
            }
        }
        printf("\n");
    }
    return 0;
}
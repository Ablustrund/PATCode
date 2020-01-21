#include <bits/stdc++.h>
using namespace std;

int m, k, n;
int main()
{
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &k);
        for (n = 1; n < 10; n++)
        {
            int res = n * k * k, temp1 = k;
            int temp2 = res;
            while(temp1 != 0)
            {
                if(temp1 % 10 == temp2 % 10)
                {
                    temp1 /= 10;
                    temp2 /= 10;
                }
                else break;
            }
            if(temp1 == 0)
            {
                printf("%d %d\n", n, res);
                break;
            }
        }
        if(n == 10) printf("No\n");
    }
        return 0;
}
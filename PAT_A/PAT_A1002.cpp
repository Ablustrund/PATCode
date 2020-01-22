#include <bits/stdc++.h>
using namespace std;
int K, temp1, counts = 0;
double temp2, expo[1010] = {0};
int main()
{
    for (int ch = 0; ch < 2; ch++)
    {
        scanf("%d", &K);
        for(int i = 0; i < K; i++)
        {
            scanf("%d%lf", &temp1, &temp2);
            if(ch == 0) expo[temp1] = temp2;
            else expo[temp1] += temp2;
        }
    }
    for (int i = 0; i < 1010; i++) if(expo[i] != 0) counts++;
    printf("%d", counts);
    for (int i = 1000; i >= 0; i--) if(expo[i] != 0) printf(" %d %.1f", i, expo[i]);
    printf("\n");
    return 0;
}
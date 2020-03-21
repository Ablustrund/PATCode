#include <bits/stdc++.h>
using namespace std;
int m, n, ins;
bool spare[1000010];
bool isPrime(int temp)
{
    if(temp == 1) return false;
    if(temp == 2 || temp == 3) return true;
    double s = sqrt(temp) + 1;
    for (int i = 2; i < s; i++)
    {
        if(temp % i == 0) return false;
    }
    return true;
}
int getPrime(int temp)
{
    while(!isPrime(temp)) temp++;
    return temp;
}
int main()
{
    fill(spare, spare + 1000010, false);
    scanf("%d%d", &m, &n);
    int t = getPrime(m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ins);
        int temp = ins % t;
        if(!spare[temp])
        {
            if(i == 0) printf("%d", temp);
            else printf(" %d", temp);
            spare[temp] = true;
        }
        else
        {
            int j;
            for (j = 1; j < t; j++)
            {
                temp = (ins + j * j) % t;
                if(!spare[temp])
                {
                    printf(" %d", temp);
                    spare[temp] = true;
                    break;
                }
            }
            if(j == t) printf(" -");
        }
    }
    printf("\n");
    return 0;
}
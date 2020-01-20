#include <bits/stdc++.h>
using namespace std;

int n, temp1, minuss[10010] = {0};
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &temp1);
        temp1 = abs(temp1 - i);
        minuss[temp1]++;
    }
    for (int i = 10000; i >= 0; i--)
    {
        if(minuss[i] >= 2) printf("%d %d\n", i, minuss[i]);
    }
    return 0;
}
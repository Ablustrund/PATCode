#include <bits/stdc++.h>
using namespace std;

int n;
double tempNum, result = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> tempNum;
        result += tempNum * (n - i + 1) * i;
    }
    printf("%.2lf\n", result);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, temp1;
set<int> SETS;
int bitSum(int temp)
{
    int sums = 0;
    while (temp != 0)
    {
        sums += temp % 10;
        temp /= 10;
    }
    return sums;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp1);
        SETS.insert(bitSum(temp1));
    }
    printf("%d\n", SETS.size());
    for (auto iter = SETS.begin(); iter != SETS.end(); iter++)
    {
        if (iter == SETS.begin())
            printf("%d", *iter);
        else
            printf(" %d", *iter);
    }
    printf("\n");
    return 0;
}
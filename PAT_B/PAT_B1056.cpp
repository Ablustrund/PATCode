#include <bits/stdc++.h>
using namespace std;

int n, sum = 0, nums[10];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j) continue;
            sum += nums[i] * 10 + nums[j];
        }
    }
    printf("%d\n", sum);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, p;
long long int nums[100010];
int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++) scanf("%lld", &nums[i]);
    sort(nums, nums + n);
    int res = -1;
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        while(j < n && nums[j] <= nums[i] * p)
        {
            j++;
        }
        if(res < j - i) res = j - i;
    }
    printf("%d\n", res);
    return 0;
}
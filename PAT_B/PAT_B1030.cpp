#include <bits/stdc++.h>
using namespace std;

int n, p, k;
vector<long long int> nums;
int main()
{
    scanf("%d%d", &n, &p);
    long long int mp = 0;
    long long int tempNum;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &tempNum);
        nums.push_back(tempNum);
    }
    sort(nums.begin(), nums.end());
    k = 0;
    int maxx = -1;
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        mp = nums[i] * p;
        for (j = k; j < n; j++)
        {
            if(nums[j] > mp)
            {
                k = j;
                break;
            }
        }
        if(j == n && maxx < j-i) maxx = j-i;
        if(maxx < k-i) maxx = k-i;
    }
    printf("%d\n", maxx);
    return 0;
}
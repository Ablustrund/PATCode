#include <bits/stdc++.h>
using namespace std;

long long int N, temp2, m, n;
bool flag = 0;
vector<long long int> nums;
bool cmp(long long int a, long long int b)
{
    return a > b;
}
int main()
{
    scanf("%lld", &N);
    for (long long int i = 0; i < N; i++)
    {
        scanf("%lld", &temp2);
        nums.push_back(temp2);
    }
    sort(nums.begin(), nums.end(), cmp);
    long long int temp = (long long int)sqrt(N);
    if(temp * temp == N)
    {
        flag = 1;
        m = n = temp;
    }
    temp++;
    for (long long int i = temp; i <= N; i++)
    {
        if(flag) break;
        for (long long int j = temp; j >= 1; j--)
        {
            temp2 = j * i;
            if(temp2 > N) continue;
            else if(temp2 == N)
            {
                m = i;
                n = j;
                flag = 1;
                break;
            }
            else break;
        }
    }
    long long countss = 0;
    for (long long int i = 0; i < m; i++)
    {
        for (long long int j = 0; j < n; j++)
        {
            if (j == 0) printf("%lld", nums[countss++]);
            else printf(" %lld", nums[countss++]);
        }
        printf("\n");
    }
        return 0;
}
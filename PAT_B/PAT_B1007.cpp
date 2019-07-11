#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> prime;

bool judge(int a)
{
    for (int i = 2; i <= sqrt(1.0 * a); i++)
    {
        if(a % i == 0) return false;
    }
    return true;
}

int main()
{
    int count = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if(judge(i)) prime.push_back(i);
    }
    sort(prime.begin(), prime.end());
    for (int i = 1; i < prime.size(); i++)
    {
        if(prime[i] - prime[i - 1] == 2) count++;
    }
    printf("%d\n", count);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, temp1;
vector<int> vec;
bool CMP(int a, int b)
{
    return a > b;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp1);
        vec.push_back(temp1);
    }
    sort(vec.begin(), vec.end(), CMP);
    int i = 1;
    if(vec[n - 1] > n)
    {
        printf("%d\n", n);
        return 0;
    }
    for (i = 1; i <= n; i++)
    {
        int Tag = true;
        for(int j = 0; j < i; j++)
        {
            if(vec[j] <= i)
            {
                Tag = false;
                break;
            }
        }
        if(Tag == false) break;
    }
    printf("%d\n", i - 1);
    return 0;
}
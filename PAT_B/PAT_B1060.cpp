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
    for(i = 1; i <= n; i++)
    {
        if(vec[i - 1] <= i) break;
    }
    printf("%d\n", i - 1);
    return 0;
}
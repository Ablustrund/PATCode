#include <bits/stdc++.h>
using namespace std;
int m, n, temp, maxx = -1, j;
unordered_map<int, int> res;
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m * n; i++)
    {
        scanf("%d", &temp);
        res[temp]++;
    }
    for(auto&i:res)
    {
        if(maxx < i.second)
        {
            maxx = i.second;
            j = i.first;
        }
    }
    printf("%d\n", j);
    return 0;
}
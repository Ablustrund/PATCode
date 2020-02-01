#include <bits/stdc++.h>
using namespace std;
int n, temp, counts[10010] = {0};
vector<int> orders;
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        counts[temp]++;
        orders.push_back(temp);
    }
    for(auto&i:orders)
    {
        if(counts[i] == 1)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}
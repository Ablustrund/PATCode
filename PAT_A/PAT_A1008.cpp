#include <bits/stdc++.h>
using namespace std;
int n, preFloor = 0, res = 0, nextFloor;
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nextFloor);
        if(nextFloor - preFloor > 0) res += (nextFloor - preFloor) * 6;
        else res += (preFloor - nextFloor) * 4;
        preFloor = nextFloor;
    }
    printf("%d\n", res + 5 * n);
    return 0;
}
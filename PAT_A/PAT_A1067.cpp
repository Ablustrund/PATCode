#include <bits/stdc++.h>
using namespace std;
int n, numbers[100010], res = 0, k, zeroindex, leftright = 0;
int findPos[100010];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
        findPos[numbers[i]] = i;
        if(numbers[i] == 0) zeroindex = i;
    }
    while(1)
    {
        if(zeroindex == 0)
        {
            for(k = leftright + 1; k < n; k++) if(numbers[k] != k) break;//这里leftright加速，因为0-leftright之间的元素一定是排序完成的，所以之间一定没有未完成排序的元素
            if(k == n) break;
            numbers[zeroindex] = numbers[k];
            findPos[numbers[zeroindex]] = zeroindex;
            numbers[k] = 0;
            zeroindex = leftright = k;
            res++;
        }
        numbers[zeroindex] = zeroindex;
        numbers[findPos[zeroindex]] = 0;
        swap(findPos[zeroindex], zeroindex);
        res++;
    }
    printf("%d\n", res);
    return 0;
}
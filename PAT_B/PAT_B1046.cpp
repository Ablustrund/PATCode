#include <bits/stdc++.h>
using namespace std;

int n;
int aHowl, aTach, bHowl, bTach, sums;
int aWinNums = 0, bWinNums = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &aHowl, &aTach, &bHowl, &bTach);
        sums = (aHowl + bHowl);
        if(aTach == sums && bTach != sums) aWinNums++;
        else if(aTach != sums && bTach == sums) bWinNums++;
    }
    printf("%d %d\n", bWinNums, aWinNums);
    return 0;
}
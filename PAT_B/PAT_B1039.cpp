#include <bits/stdc++.h>
using namespace std;

string originalStr, checkStr;
int jew[1010];
int oriStrLen, cheStrLen, sameCount, flag = 1;
int main()
{
    sameCount = 0;
    fill(jew, jew + 1010, 0);
    cin >> originalStr >> checkStr;
    oriStrLen = originalStr.length();
    cheStrLen = checkStr.length();
    for(int i = 0; i < oriStrLen; i++)
    {
        jew[originalStr[i]-0]++;
    }
    for (int i = 0; i < cheStrLen; i++)
    {
        if(jew[checkStr[i]-0] == 0)
        {
            flag = 0;
            continue;
        }
        jew[checkStr[i] - 0]--;
        sameCount++;
    }
    if(flag == 0) printf("No %d\n", cheStrLen-sameCount);
    else printf("Yes %d\n", oriStrLen-sameCount);
    return 0;
}
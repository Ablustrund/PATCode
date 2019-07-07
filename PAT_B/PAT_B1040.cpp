#include <stdio.h>
#include <iostream>

using namespace std;
string PATStr;
int leftNumP[100010] = {0};
int rightNumT[100010] = {0};
long long int ans = 0;
int main()
{
    cin >> PATStr;
    if(PATStr[0] == 'P')
        leftNumP[0] = 1;
    for (int i = 1; i < PATStr.length(); i++)
    {
        if(PATStr[i] == 'P')
            leftNumP[i] = leftNumP[i - 1] + 1;
        else
            leftNumP[i] = leftNumP[i - 1];
    }
    if(PATStr[PATStr.length() - 1] == 'T')
        rightNumT[PATStr.length() - 1] = 1;
    for (int i = PATStr.length() - 2; i >= 0; i--)
    {
        if(PATStr[i] == 'T')
            rightNumT[i] = rightNumT[i + 1] + 1;
        else
            rightNumT[i] = rightNumT[i + 1];
        if(PATStr[i] == 'A')
        {
            ans += (long long int)(leftNumP[i - 1] * rightNumT[i + 1]);
            ans = ans % 1000000007;
        }
    }
    printf("%lld\n", ans);

    return 0;
}
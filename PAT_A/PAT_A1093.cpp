#include <bits/stdc++.h>
using namespace std;
int pNum[100010], tNum[100010], pCount = 0, tCount = 0, res = 0;
string str;
int main()
{
    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        pNum[i] = pCount;
        tNum[i] = tCount;
        if(str[i] == 'P') pCount++;
        else if(str[i] == 'T') tCount++;
    }
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == 'A') res = (res + (pNum[i] * (tCount - tNum[i]) % 1000000007)) % 1000000007;
    }
    printf("%d\n", res);
    return 0;
}
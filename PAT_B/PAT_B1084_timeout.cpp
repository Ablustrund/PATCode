#include <bits/stdc++.h>
using namespace std;
int d, n;
string itos(int nums)
{
    string rtnStr = "", tempStr = "";
    while(nums != 0)
    {
        tempStr = "0";
        tempStr[0] += nums % 10;
        rtnStr = tempStr + rtnStr;
        nums /= 10;
    }
    return rtnStr;
}
string resolve(string str)
{
    string rtnStr = "";
    int i = 0, k = 0, sameCh = 0;
    while(i < str.size())
    {
        sameCh = 0;
        while(k < str.size() && str[i] == str[k])
        {
            sameCh++;
            k++;
        }
        rtnStr = rtnStr + str[i] + itos(sameCh);
        i = k;
    }
    return rtnStr;
}
int main()
{
    scanf("%d%d", &d, &n);
    n--;
    string str = "0";
    str[0] += d;
    while(n--) str = resolve(str);
    cout << str << endl;
    return 0;
}
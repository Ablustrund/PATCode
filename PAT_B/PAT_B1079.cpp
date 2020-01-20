#include <bits/stdc++.h>
using namespace std;

int n = 10;
string str1, str2, sumStr;
bool jungle(string temp)
{
    for (int i = 0; i < temp.size() / 2; i++)
    {
        if(temp[i] != temp[temp.size()-i-1]) return false;
    }
    return true;
}
string reverseStr(string temp)
{
    string outStr = "";
    for(int i = 0; i < temp.size(); i++) outStr = temp[i] + outStr;
    return outStr;
}
string str1AndStr2(string temp1, string temp2)
{
    int carryNums = 0;
    string outStr = "", midStr;
    for (int i = temp1.size() - 1; i >= 0; i--)
    {
        midStr = "0";
        midStr[0] += (temp1[i] - '0' + temp2[i] - '0' + carryNums) % 10;
        outStr = midStr + outStr;   
        carryNums = (temp1[i] - '0' + temp2[i] - '0' + carryNums) / 10;
    }
    if(carryNums != 0)
    {
        midStr = "0";
        midStr[0] += carryNums;
        outStr = midStr + outStr;
    }
    return outStr;
}
int main()
{
    cin >> str1;
    sumStr = str1;
    while(n--)
    {
        if(jungle(sumStr))
        {
            printf("%s is a palindromic number.\n", sumStr.c_str());
            break;
        }
        else
        {
            str2 = reverseStr(str1);
            sumStr = str1AndStr2(str1, str2);
            printf("%s + %s = %s\n", str1.c_str(), str2.c_str(), sumStr.c_str());
            str1 = sumStr;
        }
    }
    if(n == -1) printf("Not found in 10 iterations.\n");
    return 0;
}
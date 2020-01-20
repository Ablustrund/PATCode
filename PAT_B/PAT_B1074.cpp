#include <bits/stdc++.h>
using namespace std;

int main()
{
    string strFlag, str1, str2, resultStr;
    cin >> strFlag >> str1 >> str2;
    strFlag = "0000000" + strFlag;
    while(str1.size() < strFlag.size() || str2.size() < strFlag.size())
    {
        if(str1.size() < strFlag.size()) str1 = "0" + str1;
        if(str2.size() < strFlag.size()) str2 = "0" + str2;
    }
    int carryNum = 0, modNum = 0, i;
    for (i = str1.size() - 1; i >= 0; i--)
    {
        modNum = strFlag[i] - '0' == 0 ? 10 : strFlag[i] - '0';
        string tempStr = "0";
        tempStr[0] += (str1[i] - '0' + str2[i] - '0' + carryNum) % modNum;
        resultStr = tempStr + resultStr;   
        carryNum = (str1[i] - '0' + str2[i] - '0' + carryNum) / modNum;
    }
    while(resultStr.size() != 1 && resultStr[0] == '0') resultStr.erase(resultStr.begin());
    cout << resultStr << endl;
    return 0;
}
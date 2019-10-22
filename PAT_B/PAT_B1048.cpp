#include <bits/stdc++.h>
using namespace std;

char items[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
string strA, strB, outputStr;
int flag = 1, temp;
int main()
{
    cin >> strA >> strB;
    if(strA.length() < strB.length()) strA.insert(0, strB.length() - strA.length(), '0');
    else strB.insert(0, strA.length() - strB.length(), '0');
    int strALen = strA.length(), strBLen = strB.length();
    int loops = strBLen;
    for (int i = 1; i <= loops; i++)
    {
        if (flag == 1)
        {
            outputStr.insert(0, 1, items[(strA[strALen - i] - '0' + strB[strBLen - i] - '0') % 13]);
            flag = 0;
        }
        else
        {
            temp = strB[strBLen - i] - strA[strALen - i];
            outputStr.insert(0, 1, items[temp < 0 ? temp + 10 : temp]);
            flag = 1;
        }
    }
    cout << outputStr << endl;
    return 0;
}
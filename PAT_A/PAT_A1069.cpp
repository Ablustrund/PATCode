#include <bits/stdc++.h>
using namespace std;

string str;
bool cmp(char &a, char &b)
{
    return a > b;
}

string itos(int number)
{
    string temp = "";
    while(number != 0)
    {
        temp.insert(temp.begin(), '0' + number % 10);
        number /= 10;
    }
    while(temp.length() != 4)
    {
        temp.insert(temp.begin(), '0');
    }
    return temp;
}

int main()
{
    cin >> str;
    while(str.length() != 4)
    {
        str.insert(str.begin(), '0');
    }
    if(str[0] == str[1] && str[1] == str[2] && str[2] == str[3])
    {
        printf("%s - %s = 0000\n", str.c_str(), str.c_str());
    }
    else
    {
        string strBig = "", strSmall = "";
        sort(str.begin(), str.end());
        strSmall = str;
        sort(str.begin(), str.end(), cmp);
        strBig = str;
        while(stoi(strBig) - stoi(strSmall) != 6174)
        {
            printf("%s - %s = %04d\n", strBig.c_str(), strSmall.c_str(), stoi(strBig) - stoi(strSmall));
            str = itos(stoi(strBig) - stoi(strSmall));
            sort(str.begin(), str.end());
            strSmall = str;
            sort(str.begin(), str.end(), cmp);
            strBig = str;
        }
        printf("%s - %s = 6174\n", strBig.c_str(), strSmall.c_str());
    }
    return 0;
}
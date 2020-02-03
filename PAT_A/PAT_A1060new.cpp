#include <bits/stdc++.h>
using namespace std;
int k, ex1, ex2;
string a, b;
int eraseZero(string &str)
{
    int tempEx = 0;
    while(str.size() > 1 && str[0] == '0') str.erase(str.begin());
    if(str[0] == '.') str.insert(str.begin(), '0');
    int pos = str.find('.');
    if(str[0] == '0' && pos != string::npos)
    {
        while(str[2] == '0')
        {
            tempEx--;
            str.erase(str.begin() + 2);
        }
        if(str.size() == 2) tempEx = 0;
    }
    else
    {
        if(pos == string::npos)
        {
            if(str[0] == '0') tempEx = 0;
            else tempEx = str.size();
            str = "0." + str;
        }
        else
        {
            tempEx = pos;
            str.erase(str.begin() + pos);
            str = "0." + str;
        }
    }
    while(str.size() > k + 2) str.erase(str.begin() + str.size() - 1);
    while( str.size() < k + 2) str.insert(str.end(), '0');
    return tempEx;
}
int main()
{
    cin >> k >> a >> b;
    ex1 = eraseZero(a);
    ex2 = eraseZero(b);
    if(a == b && ex1 == ex2) printf("YES %s*10^%d\n", a.c_str(), ex1);
    else printf("NO %s*10^%d %s*10^%d\n", a.c_str(), ex1, b.c_str(), ex2);
    return 0;
}
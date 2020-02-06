#include <iostream>
#include <string>
using namespace std;
int t;
string tempa, tempb, tempc;
string addstr(string str1, string str2)
{
    int carrynum = 0;
    string res = "";
    while (str1.size() < str2.size()) str1.insert(str1.begin(), '0');
    while (str1.size() > str2.size()) str2.insert(str2.begin(), '0');
    for (int i = str1.size() - 1; i >= 0; i--)
    {
        carrynum = carrynum + str1[i] - '0' + str2[i] - '0';
        res.insert(res.begin(), '0' + carrynum % 10);
        carrynum /= 10;
    }
    if (carrynum != 0) res.insert(res.begin(), '0' + carrynum);
    while (res.size() > 1 && res[0] == '0') res.erase(res.begin());
    return res;
}
int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        string a = "0", b = "0", c = "0", d = "0", e = "0", f = "0";// compare a+b+c with d+e+f
        cin >> tempa >> tempb >> tempc;
        if (tempa[0] == '-')
        {
            tempa.erase(tempa.begin());
            d = tempa;
        }
        else a = tempa;
        if (tempb[0] == '-')
        {
            tempb.erase(tempb.begin());
            e = tempb;
        }
        else b = tempb;
        if (tempc[0] == '-')
        {
            tempc.erase(tempc.begin());
            c = tempc;
        }
        else f = tempc;
        string res1 = addstr(addstr(a, b), c);
        string res2 = addstr(addstr(d, e), f);
        if(res1.size() > res2.size() || (res1.size() == res2.size() && res1 > res2)) printf("Case #%d: true\n", i+1);
        else printf("Case #%d: false\n", i+1);
    }
    return 0;
}
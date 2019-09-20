#include <bits/stdc++.h>
using namespace std;

struct Number
{
    int fenzi, fenmu;
    bool symbol;
    Number(int _fenzi = 0, int _fenmu = 0, bool _symbol = 0)
    {
        fenzi = _fenzi;
        fenmu = _fenmu;
        symbol = _symbol;
    }
} a, b;

int stringToInt(string str)
{
    int sum = 0;
    int k = 1;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        sum += k * (str[i] - '0');
        k *= 10;
    }
    return sum;
}

int gy(int a, int b)
{
    int t;
    if (a < b)
        t = a, a = b, b = t;
    if (b == 0)
        return a;
    t = a % b;
    while (t != 0)
    {
        a = b;
        b = t;
        t = a % b;
    }
    return b;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    if (str1[0] == '-')
    {
        a.symbol = 1;
        str1.erase(0, 1);
    }
    int pos1 = str1.find("/");
    string tempStr = str1.substr(0, pos1);
    a.fenzi = stringToInt(tempStr);
    str1.erase(0, pos1 + 1);
    a.fenmu = stringToInt(str1);
    if (str2[0] == '-')
    {
        b.symbol = 1;
        str2.erase(0, 1);
    }
    pos1 = str2.find("/");
    tempStr = str2.substr(0, pos1);
    b.fenzi = stringToInt(tempStr);
    str2.erase(0, pos1 + 1);
    b.fenmu = stringToInt(str2);
    int m = gy(a.fenmu, b.fenmu);//最大公因数
    int n = a.fenmu * b.fenmu / m;//最小公倍数
    a.fenzi *= (n / a.fenmu);
    b.fenzi *= (n / b.fenmu);
    a.fenmu = b.fenmu = n;
    cout << a.symbol << " " << a.fenzi << " " << a.fenmu << " " << b.symbol << " " << b.fenzi << " " << b.fenmu << endl;

    return 0;
}
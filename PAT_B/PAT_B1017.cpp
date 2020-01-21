#include <bits/stdc++.h>
using namespace std;
string str, res = "";
int shang, yushu = 0;
int main()
{
    cin >> str >> shang;
    for (int i = 0; i < str.size(); i++)
    {
        yushu = yushu * 10 + (str[i] - '0');
        res += to_string(yushu / shang);
        yushu %= shang;
    }
    while(res.size() != 1 && res[0] == '0') res.erase(res.begin());
    cout << res << " " << yushu << endl;
    return 0;
}
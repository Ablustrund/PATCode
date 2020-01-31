#include <bits/stdc++.h>
using namespace std;
bool isPalin(string str)
{
    if(str.size() == 1) return true;
    for (int i = 0; i < str.size() / 2; i++) if(str[i] != str[str.size() - i - 1]) return false;
    return true;
}
string rev(string str)
{
    string res = "";
    for(int i = 0; i < str.size(); i++) res.insert(res.begin(), str[i]);
    return res;
}
string addString(string str1, string str2)
{
    string res = "";
    int carryNum = 0;
    for (int i = str1.size() - 1; i >= 0; i--)
    {
        int temp = str1[i] - '0' + str2[i] - '0' + carryNum;
        res.insert(res.begin(), '0' + temp % 10);
        carryNum = temp / 10;
    }
    if(carryNum != 0) res.insert(res.begin(), '0' + carryNum);
    return res;
}
int main()
{
    string str;
    int K;
    cin >> str >> K;
    for (int i = 0; i < K; i++)
    {
        if(isPalin(str))
        {
            printf("%s\n%d\n", str.c_str(), i);
            return 0;
        }
        str = addString(str, rev(str));
    }
    printf("%s\n%d\n", str.c_str(), K);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
set<char> set1, set2;
string doubleIt(string str)
{
    string res = "";
    int carryNum = 0, tempNum;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        tempNum = 2 * (str[i] - '0') + carryNum;
        res.insert(res.begin(), '0' + (tempNum) % 10);
        carryNum = tempNum / 10;
    }
    if(carryNum != 0) res.insert(res.begin(), '0' + carryNum);
    return res;
}
int main()
{
    string str1;
    cin >> str1;
    string str2 = doubleIt(str1);
    if(str1.size() != str2.size()) printf("No\n");
    else
    {
        for (int i = 0; i < str1.size(); i++) {set1.insert(str1[i]); set2.insert(str2[i]);}
        if(set1 != set2) printf("No\n"); else printf("Yes\n");
    }
    printf("%s\n", str2.c_str());
    return 0;
}
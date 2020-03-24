#include <bits/stdc++.h>
using namespace std;
int n;
char fs[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char ss[13][5] = {"xxx", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string s;
map<string, int> map1, map2;
void e2m(string s)
{
    int t = stoi(s);
    if(t >= 0 && t < 13) printf("%s\n", fs[t]);
    else
    {
        if(t % 13 == 0) printf("%s\n", ss[t / 13]);
        else printf("%s %s\n", ss[t / 13], fs[t % 13]);
    }
    return;
}
void m2e(string s)
{
    int pos = s.find(' '), a = 0;
    if(pos == string::npos)
    {
        if(map1.find(s) != map1.end()) a = map1[s];
        else a = map2[s] * 13;
    }
    else
    {
        string s1 = s.substr(0, pos);
        a = 13 * map2[s1];
        s = s.erase(0, pos + 1);
        a += map1[s];
    }
    printf("%d\n", a);
    return;
}
int main()
{
    map1["tret"] = 0, map1["jan"] = 1, map1["feb"] = 2, map1["mar"] = 3, map1["apr"] = 4, map1["may"] = 5;
    map1["jun"] = 6, map1["jly"] = 7, map1["aug"] = 8, map1["sep"] = 9, map1["oct"] = 10, map1["nov"] = 11, map1["dec"] = 12;
    map2["tam"] = 1, map2["hel"] = 2, map2["maa"] = 3, map2["huh"] = 4, map2["tou"] = 5, map2["kes"] = 6;
    map2["hei"] = 7, map2["elo"] = 8, map2["syy"] = 9, map2["lok"] = 10, map2["mer"] = 11, map2["jou"] = 12;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        if(s[0] >= '0' && s[0] <= '9') e2m(s);
        else m2e(s);
    }
    return 0;
}
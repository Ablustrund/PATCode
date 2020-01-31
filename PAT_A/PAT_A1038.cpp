#include <bits/stdc++.h>
using namespace std;
int n;
string temp, res = "";
vector<string> resList;
bool cmp(const string &a, const string &b) { return a + b < b + a; }
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        resList.push_back(temp);
    }
    sort(resList.begin(), resList.end(), cmp);
    for(auto&i:resList) res += i;
    while(res.size() != 1 && res[0] == '0') res.erase(res.begin());
    printf("%s\n", res.c_str());
    return 0;
}
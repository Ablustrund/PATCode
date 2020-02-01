#include <bits/stdc++.h>
using namespace std;
string str;
bool dp[1010][1010];
int main()
{
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) dp[i][i] = true;
    for (int i = 0; i + 1 < str.size(); i++) if(str[i+1] == str[i]) dp[i][i+1] = true;
    for (int i = 2; i < str.size(); i++)
    {
        for (int j = 0; j + i < str.size(); j++)
        {
            if(dp[j + 1][i + j - 1] == 1 && str[j] == str[i + j]) dp[j][i + j] = true;
        }
    }
    int res = -1;
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 0; j < str.size(); j++)
        {
            if(dp[i][j] && j - i + 1 > res) res = j - i + 1;
        }
    }
    printf("%d\n", res);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ansStr, tempStr;
    vector<string> strVec;
    int i, n;
    cin >> ansStr >> n;
    getchar();
    while(1)
    {
        getline(cin, tempStr);
        if(tempStr == "#") break;
        else strVec.push_back(tempStr);
    }
    for (i = 0; i < n; i++)
    {
        if(i == strVec.size()) break;
        if(strVec[i] == ansStr)
        {
            printf("Welcome in\n");
            return 0;
        }
        else printf("Wrong password: %s\n", strVec[i].c_str());
    }
    if(i == n) printf("Account locked\n");
    return 0;
}
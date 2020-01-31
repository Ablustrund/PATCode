#include <bits/stdc++.h>
using namespace std;
int n, haveConf;
string str;
vector<string> res;
int main()
{
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        haveConf = false;
        int pos = str.find(' ');
        for (int i = pos; i < str.size(); i++)
        {
            if(str[i] == '1' || str[i] == '0' || str[i] == 'l' || str[i] == 'O') haveConf = true;
            if(str[i] == '1') str[i] = '@';
            else if(str[i] == '0') str[i] = '%';
            else if(str[i] == 'l') str[i] = 'L';
            else if(str[i] == 'O') str[i] = 'o';
        }
        if(haveConf) res.push_back(str);
    }
    if(res.size() == 0 && n == 1) printf("There is %d account and no account is modified\n", n);
    else if(res.size() == 0) printf("There are %d accounts and no account is modified\n", n);
    else
    {
        printf("%d\n", res.size());
        for(auto&i:res) printf("%s\n", i.c_str());
    }
    return 0;
}
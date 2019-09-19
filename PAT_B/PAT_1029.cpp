#include <bits/stdc++.h>
using namespace std;

string str1, str2;
bool flag[200] = {false};//0:'_', 1-26:大写字母, 27-37:数字
int main()
{
    cin >> str1 >> str2;
    for (int i = 0; i < str1.size(); i++)
        if(str1[i] >= 'a' && str1[i] <= 'z') str1[i] = 'A' + (str1[i] - 'a');
    for (int i = 0; i < str2.size(); i++)
        if(str2[i] >= 'a' && str2[i] <= 'z') str2[i] = 'A' + (str2[i] - 'a');
    int k = 0;
    int maxk = str2.size();
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] == str2[k])
        {
            if(k < maxk-1) k++;
            continue;
        }
        else
        {
            if(str1[i] == '_' && flag[0] == 0)
            {
                flag[0] = 1;
                printf("%c", str1[i]);
            }
            else if(str1[i] >= 'A' && str1[i] <= 'Z' && flag[1+str1[i]-'A'] == 0)
            {
                flag[1 + str1[i] - 'A'] = 1;
                printf("%c", str1[i]);
            }
            else if(str1[i] >= '0' && str1[i] <= '9' && flag[27+str1[i]-'0'] == 0)
            {
                flag[27 + str1[i] - '0'] = 1;
                printf("%c", str1[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
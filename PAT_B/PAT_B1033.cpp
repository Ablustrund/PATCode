#include <bits/stdc++.h>
using namespace std;

string str1, str2;
bool broken[66] = {false};//0-25:小写字母, 26-51:大写字母, 52-61数字, 62逗号, 63逗点, 64-, 65_
int main()
{
    getline(cin, str1);
    getline(cin, str2);
    for (int i = 0; i < str1.size(); i++)
    {
        if(str1[i] == ',') broken[62] = 1;
        else if(str1[i] == '.') broken[63] = 1;
        else if(str1[i] == '-') broken[64] = 1;
        else if(str1[i] == '_') broken[65] = 1;
        else if(str1[i] == '+')
        {
            for (int j = 26; j <= 51; j++) broken[j] = 1;
        }
        else if(str1[i] >= '0' && str1[i] <= '9') broken[str1[i] - '0' + 52] = 1;
        else if(str1[i] >= 'A' && str1[i] <= 'Z') broken[str1[i] - 'A'] = broken[str1[i] - 'A' + 26] = 1;
    }
    for(int i = 0; i < str2.size(); i++)
    {
        if(str2[i] == ',' && !broken[62]) printf("%c", str2[i]);
        else if(str2[i] == '.' && !broken[63]) printf("%c", str2[i]);
        else if(str2[i] == '-' && !broken[64]) printf("%c", str2[i]);
        else if(str2[i] == '_' && !broken[65]) printf("%c", str2[i]);
        else if(str2[i] >= '0' && str2[i] <= '9' && !broken[str2[i] - '0' + 52]) printf("%c", str2[i]);
        else if(str2[i] >= 'A' && str2[i] <= 'Z' && !broken[str2[i] - 'A' + 26]) printf("%c", str2[i]);
        else if(str2[i] >= 'a' && str2[i] <= 'z' && !broken[str2[i] - 'a']) printf("%c", str2[i]);
    }
    printf("\n");
    return 0;
}
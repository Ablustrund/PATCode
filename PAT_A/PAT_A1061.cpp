#include <bits/stdc++.h>
using namespace std;
int tag = 1;
string str1, str2, str3, str4;
char weeks[7][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
    cin >> str1 >> str2 >> str3 >> str4;
    for (int i = 0; i < min(str1.size(), str2.size()); i++)
    {
        if(tag == 1 && str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G')
        {
            tag = 2;
            printf("%s ", weeks[str1[i] - 'A']);
            continue;
        }
        if(tag == 2 && str1[i] == str2[i] && ((str1[i] >= 'A' && str1[i] <= 'N') || (str1[i] >= '0' && str1[i] <= '9')))
        {
            if((str1[i] >= 'A' && str1[i] <= 'N')) printf("%02d:", str1[i] - 'A' + 10);
            else printf("%02d:", str1[i] - '0');
            break;
        }
    }
    for (int i = 0; i < min(str3.size(), str4.size()); i++)
    {
        if(str3[i] == str4[i] && ((str3[i] >= 'a' && str4[i] <= 'z') || (str3[i] >= 'A' && str4[i] <= 'Z')))
        {
            printf("%02d\n", i);
            return 0;
        }
    }
    return 0;
}
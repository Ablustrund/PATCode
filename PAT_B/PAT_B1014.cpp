#include <bits/stdc++.h>
using namespace std;

string str1, str2, str3, str4;
char weeks[7][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int flag = 0;
int main()
{
    cin >> str1 >> str2 >> str3 >> str4;
    int minLen = min(str1.size(), str2.size());
    for (int i = 0; i < minLen; i++)
    {
        if(str1[i] != str2[i]) continue;
        if(flag == 0 && str1[i] >= 'A' && str1[i] <= 'G')
        {
            printf("%s ", weeks[str1[i] - 'A']);
            flag++;
            continue;
        }
        if(flag == 1 && ((str1[i] >= '0' && str1[i] <= '9') || (str1[i] >= 'A' && str1[i] <= 'N')))
        {
            if(str1[i] >= '0' && str1[i] <= '9') printf("0%d:", str1[i] - '0');
            else printf("%d:", str1[i] - 'A' + 10);
            break;
        }
    }
    minLen = min(str3.size(), str4.size());
    for (int i = 0; i < minLen; i++)
    {
        if(str3[i] != str4[i]) continue;
        if((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z'))
        {
            if(i < 10) printf("0%d\n", i);
            else printf("%d\n", i);
            break;
        }
    }
        return 0;
}
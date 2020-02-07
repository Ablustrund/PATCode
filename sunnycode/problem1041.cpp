#include <bits/stdc++.h>
using namespace std;
int indexx;
string str, str1, str2;
int main()
{
    cin >> str >> indexx;
    str = str.substr(0, indexx);
    for (int i = str.size()-2; i >= 0; i--)
    {
        str1 = str;
        str2 = str1.substr(0, i+1);
        str1 = str1.erase(0, str.size() - i - 1);
        if(str1 == str2)
        {
            printf("%d\n", str1.size());
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
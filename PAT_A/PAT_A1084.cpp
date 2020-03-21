#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1, str2;
    set<char> set1, set2;
    cin >> str1 >> str2;
    for (int i = 0; i < str2.size(); i++)
    {
        if(str2[i] >= 'a' && str2[i] <= 'z') str2[i] = str2[i] - 'a' + 'A';
        set2.insert(str2[i]);
    }
    for (int i = 0; i < str1.size(); i++)
    {
        if(str1[i] >= 'a' && str1[i] <= 'z') str1[i] = str1[i] - 'a' + 'A';
        if(set2.find(str1[i]) == set2.end())
        {
            if(set1.find(str1[i]) == set1.end())
            {
                printf("%c", str1[i]);
                set1.insert(str1[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string str;
int arrays[26];
int main()
{
    fill(arrays, arrays + 26, 0);
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] - 'A' + 'a';
    }
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z') arrays[str[i] - 'a']++;
    }
    int k = -1;
    int site = 0;
    for (int i = 0; i < 26; i++)
    {
        if(arrays[i] > k)
        {
            k = arrays[i];
            site = i;
        }
    }
    printf("%c %d\n", 'a' + site, k);
    return 0;
}
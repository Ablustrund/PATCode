#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main()
{
    getline(cin, s1);
    getline(cin, s2);
    for(auto&i:s1)
    {
        if(s2.find(i) == string::npos) printf("%c", i);
    }
    printf("\n");
    return 0;
}
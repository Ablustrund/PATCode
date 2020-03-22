#include <bits/stdc++.h>
using namespace std;
string str1, str2;
int resM = 0;
map<char, int> beads;
int main()
{
    getline(cin, str1);
    getline(cin, str2);
    for (int i = 0; i < str1.size(); i++) beads[str1[i]]++;
    for(int i = 0; i < str2.size(); i++)
    {
        if(beads.find(str2[i]) == beads.end() || beads[str2[i]] == 0)
        {
            resM++;
        }
        else
        {
            beads[str2[i]]--;
        }
    }
    if(resM == 0) printf("Yes %d\n", str1.size() - str2.size());
    else printf("No %d\n", resM);
    return 0;
}
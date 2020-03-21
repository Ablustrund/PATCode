#include <bits/stdc++.h>
using namespace std;
string str;
char chinese[11][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "Fu"};
bool firFlag = true;
void print(int tag)
{
    if(firFlag)
    {
        printf("%s", chinese[tag]);
        firFlag = false;
    }
    else printf(" %s", chinese[tag]);
    return;
}
int main()
{
    cin >> str;
    if(str[0] == '-')
    {
        str.erase(str.begin());
        print(10);
    }
    while(str.size() != 0)
    {
        print(str[0] - '0');
        if(str.size() % 9 == 0) printf(" Yi");
        if(str.size() == 5) printf(" Wan");
        else if(str.size() == 8 || str.size() == 4) printf(" Qian");
        else if(str.size()  == 7 || str.size() == 3) printf(" Bai");
        else if(str.size() == 6 || str.size() == 2) printf(" Shi");
        str.erase(str.begin());
        if(str[0] == '0')
        {
            int i = 0;
            for (int j = 0; j < str.size(); j++)
            {
                if(str[j] == '0') i++;
                else break;
            }
            if(str.size() >= 5 && str.size() <= 8) printf(" Wan");
            if(i == str.size()) return 0;
            else
            {
                print(0);
                str.erase(str.begin(), str.begin() + i);
            }
        }
    }
    printf("\n");
    return 0;
}
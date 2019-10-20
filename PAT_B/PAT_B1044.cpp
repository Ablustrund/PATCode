#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

map<string, int> pos1 = {
    {"tret", 0}, {"jan", 1}, {"feb", 2}, {"mar", 3}, {"apr", 4}, {"may", 5}, {"jun", 6}, {"jly", 7}, {"aug", 8}, {"sep", 9}, {"oct", 10}, {"nov", 11}, {"dec", 12}
};
map<string, int> pos2 = {
    {"tam", 1}, {"hel", 2}, {"maa", 3}, {"huh", 4}, {"tou", 5}, {"kes", 6}, {"hei", 7}, {"elo", 8}, {"syy", 9}, {"lok", 10}, {"mer", 11}, {"jou", 12}
};
char ePos1[13][10] = {
    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
};
char ePos2[13][10] = {
    "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};
int m, tempNum, blankPos, temp2, temp1;
string str, str2;
stringstream ss;
int main()
{
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++)
    {
        getline(cin, str);
        if(str[0] >= '0' && str[0] <='9')
        {
            ss.clear();
            ss.str("");
            ss << str;
            ss >> tempNum;
            if(tempNum <= 12) printf("%s\n", ePos1[tempNum]);
            else
            {
                if(tempNum % 13 != 0)
                {
                    printf("%s ", ePos2[tempNum / 13]);
                    tempNum %= 13;
                    printf("%s\n", ePos1[tempNum]);
                }
                else printf("%s\n", ePos2[tempNum / 13]);
            }
        }
        else
        {
            blankPos = str.find(" ");
            if(blankPos == string::npos)
            {
                if(pos1.count(str)) printf("%d\n", pos1[str]);
                else printf("%d\n", 13 * pos2[str]);
            }
            else
            {
                str2 = str.substr(0, blankPos);
                str.erase(0, blankPos + 1);
                printf("%d\n", pos2[str2] * 13 + pos1[str]);
            }
        }
    }
        return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool symbol = 0;
bool direc = 0;
int main()
{
    string str;
    cin >> str;
    if(str[0] == '-') symbol = 1;
    str.erase(0, 1);
    int commaPos = str.find(".");
    str.erase(commaPos, 1);
    int ePos = str.find("E");
    string ex = str.substr(ePos+1);
    str.erase(str.begin() + ePos, str.end());
    if(ex[0] == '-') direc = 1;
    ex.erase(0, 1);
    stringstream ss;
    ss.str("");
    ss.clear();
    ss << ex;
    int exNum = 0;
    ss >> exNum;
    //cout << str << " " << ex << " " <<  exNum << endl;
    if(symbol == 1) printf("-");
    if(exNum == 0)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if(i == commaPos) printf(".");
            printf("%c", str[i]);
        }
        printf("\n");
    }
    else if(direc == 1)
    {
        for (int i = 0; i < exNum; i++)
        {
            if(i == commaPos) printf(".");
            printf("0");
        }
        cout << str << endl;
    }
    else if(direc == 0)
    {
        if(exNum >= str.size()-1)
        {
            cout << str;
            for (int i = 0; i < exNum-str.size()+1; i++) printf("0");
            printf("\n");
        }
        else
        {
            for(int i = 0; i < str.size(); i++)
            {
                if(i == commaPos+exNum) printf(".");
                printf("%c", str[i]);
            }
        }
    }
    return 0;
}
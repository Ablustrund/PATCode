#include <bits/stdc++.h>
using namespace std;

int n;
string str;
bool illegalFlag, haveNum, haveCh;
int main()
{
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        getline(cin, str);
        illegalFlag = haveNum = haveCh = false;
        if(str.size() < 6) printf("Your password is tai duan le.\n");
        else
        {
            for(auto&i:str)
            {
                if(!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9') || i == '.')) illegalFlag = true;
                if(i >= '0' && i <= '9') haveNum = true;
                if((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) haveCh = true;
            }
            if(illegalFlag) printf("Your password is tai luan le.\n");
            else if(!haveNum) printf("Your password needs shu zi.\n");
            else if(!haveCh) printf("Your password needs zi mu.\n");
            else printf("Your password is wan mei.\n");
        }
    }
    return 0;
}
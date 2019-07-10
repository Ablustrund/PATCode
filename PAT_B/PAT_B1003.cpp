#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

bool judge(string str)
{
    string aStr = "";
    string tempStr = "PAT";
    int pNum = 0, tNum = 0, aNum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] != 'P' && str[i] != 'A' && str[i] != 'T') return false;
        if(str[i] == 'P') pNum++;
        if(str[i] == 'T') tNum++;
        if(str[i] == 'A') aNum++;
    }
    if((pNum != 1 && tNum != 1) || aNum == 0) return false;
    if(str[0] == 'P' && str[str.size() - 1] == 'T') return true;

    int j = 1;
    for (aStr = 'A'; aStr.size() <= str.size() / 2; aStr += "A", j++)
    {
        tempStr = aStr + "PAT" + aStr;
        while(tempStr.size() < str.size())
        {
            if(tempStr.size() > str.size()) break;
            //int pPos = tempStr.find('P');
            int tPos = tempStr.find('T');
            int numTc = tempStr.size() - tPos;
            string temp1 = tempStr;
            string Pb = temp1.erase(0, aStr.size());
            //cout << Pb << endl;
            Pb = Pb.erase(tPos - j, numTc);
            //cout << Pb << endl;
            string Tc = tempStr.erase(0, tempStr.size() - numTc);
            //cout << Tc << endl;
            tempStr = aStr + Pb + "A" + Tc + aStr;
            //cout << tempStr << endl;
        }
        if(tempStr == str) return true;
    }
    return false;
}

int main()
{
    int n;
    string str;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if(judge(str)) printf("YES\n");
        else printf("NO\n");
    }
}
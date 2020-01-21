#include <bits/stdc++.h>
using namespace std;
int n, pNum, tNum, aNum, flags;
string str;
int main()
{
    scanf("%d", &n);
    getchar();
    while(n--)
    {
        getline(cin, str);
        pNum = tNum = aNum = flags = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if(str[i] != 'P' && str[i] != 'A' && str[i] != 'T') {printf("NO\n"); flags = 1; break;}
            if(str[i] == 'P') pNum++;
            if(str[i] == 'T') tNum++;
            if(str[i] == 'A') aNum++;
        }
        if(flags) continue;
        if((pNum != 1 && tNum != 1) || aNum == 0) { printf("NO\n"); continue; }
        int posP = str.find('P'), posT = str.find('T');
        if(posP > posT) {printf("NO\n"); continue; }
        if((posP == 0 && posT != str.size()-1) || (posP != 0 && posT == str.size()-1)){printf("NO\n"); continue; }
        if(posT - posP >= 2 && ((posP == 0 && posT == str.size()-1) || ((str.size()-posT-1) % ((posT-posP-1)*posP) == 0))) { printf("YES\n"); continue; }
        printf("NO\n");
    }
    return 0;
}
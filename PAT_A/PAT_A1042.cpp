#include <bits/stdc++.h>
using namespace std;
int k, order[55];
vector<string> temp, res(55, "");
int main()
{
    scanf("%d", &k);
    for (int i = 1; i <= 54; i++) scanf("%d", &order[i]);
    temp.push_back("");
    for (int i = 1; i <= 13; i++)
    {
        string str = "S";
        if(i < 10) str.insert(str.end(), '0' + i);
        else
        {
            str.insert(str.end(), '1');
            str.insert(str.end(), '0' + i%10);
        }
        temp.push_back(str);
    }
        for (int i = 1; i <= 13; i++)
    {
        string str = "H";
        if(i < 10) str.insert(str.end(), '0' + i);
        else
        {
            str.insert(str.end(), '1');
            str.insert(str.end(), '0' + i%10);
        }
        temp.push_back(str);
    }
        for (int i = 1; i <= 13; i++)
    {
        string str = "C";
        if(i < 10) str.insert(str.end(), '0' + i);
        else
        {
            str.insert(str.end(), '1');
            str.insert(str.end(), '0' + i%10);
        }
        temp.push_back(str);
    }
        for (int i = 1; i <= 13; i++)
    {
        string str = "D";
        if(i < 10) str.insert(str.end(), '0' + i);
        else
        {
            str.insert(str.end(), '1');
            str.insert(str.end(), '0' + i%10);
        }
        temp.push_back(str);
    }
    temp.push_back("J1");
    temp.push_back("J2");
    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j <= 54; j++)
        {
            res[order[j]] = temp[j];
        }
        temp = res;
    }
    for(int i = 1; i < res.size(); i++) if(i == 1) printf("%s", res[i].c_str()); else printf(" %s", res[i].c_str());
    printf("\n");
    return 0;
}
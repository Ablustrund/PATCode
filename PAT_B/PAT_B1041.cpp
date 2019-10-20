#include <bits/stdc++.h>
using namespace std;

int n;
string tempCode;
int tempSite1, tempSite2;
struct student
{
    string code = "";
    int siteNum = 0;
    student(string _code = "", int _siteNum = 0)
    {
        code = _code;
        siteNum = _siteNum;
    }
} students[1010];

int main()
{
    string tempStr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> tempCode >> tempSite1 >> tempSite2;
        students[tempSite1] = student(tempCode, tempSite2);
    }
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &tempSite1);
        cout << students[tempSite1].code << " " << students[tempSite1].siteNum << endl;
    }
    return 0;
}
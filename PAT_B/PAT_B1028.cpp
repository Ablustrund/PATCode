#include <bits/stdc++.h>
using namespace std;

int n;
string strName, strDate;
struct valNode
{
    string name;
    int year, month, day;
    valNode(string _name, int _year, int _month, int _day)
    {
        name = _name;
        year = _year;
        month = _month;
        day = _day;
    }
};
stringstream ss;
int valCount = 0;
vector<valNode> peoples;
bool cmp(valNode a, valNode b)
{
    if(a.year != b.year) return a.year < b.year;
    if(a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        cin >> strName >> strDate;
        int tempYear, tempMon, tempDay;
        int pos1 = strDate.find("/");
        string temp = strDate.substr(0, pos1);
        strDate.erase(0, pos1+1);
        ss.str("");
        ss.clear();
        ss << temp;
        ss >> tempYear;
        pos1 = strDate.find("/");
        temp = strDate.substr(0, pos1);
        strDate.erase(0, pos1+1);
        ss.str("");
        ss.clear();
        ss << temp;
        ss >> tempMon;
        ss.str("");
        ss.clear();
        ss << strDate;
        ss >> tempDay;
        if(tempYear < 1814 || (tempYear == 1814 && tempMon < 9) || (tempYear == 1814 && tempMon == 9 && tempDay < 6)) continue;
        if(tempYear > 2014 || (tempYear == 2014 && tempMon > 9) || (tempYear == 2014 && tempMon == 9 && tempDay > 6)) continue;
        valCount++;
        peoples.push_back(valNode(strName, tempYear, tempMon, tempDay));
    }
    sort(peoples.begin(), peoples.end(), cmp);
    if(valCount == 0) printf("0\n");
    else printf("%d %s %s\n", valCount, peoples[0].name.c_str(), peoples[peoples.size() - 1].name.c_str());
    return 0;
}
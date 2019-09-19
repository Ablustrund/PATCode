#include <bits/stdc++.h>
using namespace std;

int n;
string strName, strDate;
struct valNode
{
    string name;
    string date;
    valNode(string _name, string _date)
    {
        name = _name;
        date = _date;
    }
};
string upp = "2014/09/06";
string downn = "1814/09/06";
int valCount = 0;
vector<valNode> peoples;
bool cmp(valNode a, valNode b)
{
    if(a.date != b.date) return a.date < b.date;
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        cin >> strName >> strDate;
        if(strDate < downn || strDate > upp) continue;
        valCount++;
        peoples.push_back(valNode(strName, strDate));
    }
    sort(peoples.begin(), peoples.end(), cmp);
    if(valCount == 0) printf("0\n");
    else printf("%d %s %s\n", valCount, peoples[0].name.c_str(), peoples[peoples.size() - 1].name.c_str());
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int m, beginTime, endTime, temph, tempm, temps;
string tempId, tempT, tempE;
struct node
{
    string id;
    string times;
    node(string _id = "", string _times = "") { id = _id;  times = _times; }
};
vector<node> selectB, selectE;
bool cmp(const node &a, const node &b) { return a.times < b.times; }
int main()
{
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        cin >> tempId >> tempT >> tempE;
        selectB.push_back(node(tempId, tempT));
        selectE.push_back(node(tempId, tempE));
    }
    sort(selectB.begin(), selectB.end(), cmp);
    sort(selectE.begin(), selectE.end(), cmp);
    printf("%s %s\n", selectB[0].id.c_str(), selectE[selectE.size() - 1].id.c_str());
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, c, tempSc;
string tempId, tempName;
struct stu
{
    string id, name;
    int sc;
    stu(string _id = "", string _name = "", int _sc = 0) { id = _id; name = _name; sc = _sc;}
};
vector<stu> res;
bool cmp1(const stu &a, const stu &b) { return a.id < b.id; }
bool cmp2(const stu &a, const stu &b) { if(a.name != b.name) return a.name < b.name; return a.id < b.id; }
bool cmp3(const stu &a, const stu &b) { if(a.sc != b.sc) return a.sc < b.sc; return a.id < b.id; }
int main()
{
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; i++)
    {
        cin >> tempId >> tempName >> tempSc;
        res.push_back(stu(tempId, tempName, tempSc));
    }
    if(c == 1) sort(res.begin(), res.end(), cmp1);
    if(c == 2) sort(res.begin(), res.end(), cmp2);
    if(c == 3) sort(res.begin(), res.end(), cmp3);
    for(auto&i:res) printf("%s %s %d\n", i.id.c_str(), i.name.c_str(), i.sc);
    return 0;
}
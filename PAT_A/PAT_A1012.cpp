#include <bits/stdc++.h>
using namespace std;
struct stu
{
    int id, cc, mm, ee, av;
    stu(int _id = 0, int _cc = 0, int _mm = 0, int _ee = 0, int _av = 0) {id = _id; cc = _cc; mm = _mm; ee = _ee; av = _av;}
};
vector<stu> students;
set<int> exists;
unordered_map<int, stu> maps;
int res[4]; //a, c, m, e;
char acme[4] = {'A', 'C', 'M', 'E'};
bool cmp1(const stu &a, const stu &b) { return a.cc > b.cc; }
bool cmp2(const stu &a, const stu &b) { return a.mm > b.mm; }
bool cmp3(const stu &a, const stu &b) { return a.ee > b.ee; }
bool cmp4(const stu &a, const stu &b) { return a.av > b.av; }
int main()
{
    int n, m, tempId, tempC, tempM, tempE;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &tempId, &tempC, &tempM, &tempE);
        exists.insert(tempId);
        int av = (tempC + tempM + tempE) / 3;
        students.push_back(stu(tempId, tempC, tempM, tempE, av));
        maps[tempId] = stu(tempId, 0, 0, 0, 0);
    }
    sort(students.begin(), students.end(), cmp1);
    for (int i = 0,k = 0; i < n; i = k) while(k < n && students[i].cc == students[k].cc) maps[students[k++].id].cc = i + 1;
    sort(students.begin(), students.end(), cmp2);
    for (int i = 0,k = 0; i < n; i = k) while(k < n && students[i].mm == students[k].mm) maps[students[k++].id].mm = i + 1;
    sort(students.begin(), students.end(), cmp3);
    for (int i = 0,k = 0; i < n; i = k) while(k < n && students[i].ee == students[k].ee) maps[students[k++].id].ee = i + 1;
    sort(students.begin(), students.end(), cmp4);
    for (int i = 0,k = 0; i < n; i = k) while(k < n && students[i].av == students[k].av) maps[students[k++].id].av = i + 1;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tempId);
        if(exists.find(tempId) == exists.end()) printf("N/A\n");
        else
        {
            res[0] = maps[tempId].av; res[1] = maps[tempId].cc; res[2] = maps[tempId].mm; res[3] = maps[tempId].ee;
            int ress = 1000000000, k = 0;
            for(int j = 0; j < 4; j++) if(ress > res[j]) {k = j; ress = res[j];}
            printf("%d %c\n", res[k], acme[k]);
        }
    }
        return 0;
}
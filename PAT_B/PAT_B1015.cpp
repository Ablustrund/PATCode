#include <bits/stdc++.h>
using namespace std;
int n, l, h;
struct student
{
    int  code, de, cai;
    student(int _code, int _de, int _cai)
    {
        code = _code;
        de = _de;
        cai = _cai;
    }
};
int tempCode, tempDe, tempCai;
vector<student> allDeCai, deWinCai, deCaiDie, otherStu;

bool cmp(student a, student b)
{
    int temp1 = a.de+a.cai;
    int temp2 = b.de+b.cai;
    if(temp1 != temp2) return temp1 > temp2;
    if(a.de != b.de) return a.de > b.de;
    return a.code < b.code;
}

int main()
{
    scanf("%d%d%d", &n, &l, &h);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tempCode, &tempDe, &tempCai);
        if(tempDe < l ||  tempCai < l) continue;
        if(tempDe >= h && tempCai >= h) allDeCai.push_back(student(tempCode, tempDe, tempCai));
        else if(tempCai < h && tempDe >= h) deWinCai.push_back(student(tempCode, tempDe, tempCai));
        else if(tempCai < h && tempDe < h && tempDe >= tempCai) deCaiDie.push_back(student(tempCode, tempDe, tempCai));
        else otherStu.push_back(student(tempCode, tempDe, tempCai));
    }
    sort(allDeCai.begin(), allDeCai.end(), cmp);
    sort(deWinCai.begin(), deWinCai.end(), cmp);
    sort(deCaiDie.begin(), deCaiDie.end(), cmp);
    sort(otherStu.begin(), otherStu.end(), cmp);
    printf("%d\n", allDeCai.size() + deWinCai.size() + deCaiDie.size() + otherStu.size());
    for (int i = 0; i < allDeCai.size(); i++) printf("%d %d %d\n", allDeCai[i].code, allDeCai[i].de, allDeCai[i].cai);
    for (int i = 0; i < deWinCai.size(); i++) printf("%d %d %d\n", deWinCai[i].code, deWinCai[i].de, deWinCai[i].cai);
    for (int i = 0; i < deCaiDie.size(); i++) printf("%d %d %d\n", deCaiDie[i].code, deCaiDie[i].de, deCaiDie[i].cai);
    for (int i = 0; i < otherStu.size(); i++) printf("%d %d %d\n", otherStu[i].code, otherStu[i].de, otherStu[i].cai);
        return 0;
}
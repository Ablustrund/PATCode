#include <bits/stdc++.h>
using namespace std;
int n, k, tempH, tempM, tempS, tempProc, tempT;
const int beginTime = 8 * 3600, endTime = 17 * 3600;
double avge = 0;
struct peo
{
    int arrTime, proc;
    peo(int _arrTime, int _proc) { arrTime = _arrTime;  proc = _proc;}
};
vector<peo> peoples;
priority_queue<int, vector<int>, greater<int>> q;
bool cmp(const peo &a, const peo &b) { return a.arrTime < b.arrTime; }
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d", &tempH, &tempM, &tempS, &tempProc);
        tempT = tempH * 3600 + tempM * 60 + tempS;
        if(tempT > endTime) continue;
        peoples.push_back(peo(tempT, tempProc));
    }
    sort(peoples.begin(), peoples.end(), cmp);
    for (int i = 0; i < k; i++) q.push(beginTime);
    for (int i = 0; i < peoples.size(); i++)
    {
        if(q.top() > peoples[i].arrTime) avge += (q.top() - peoples[i].arrTime);
        int tempS = q.top();
        q.pop();
        q.push(max(peoples[i].arrTime, tempS) + peoples[i].proc * 60);
    }
    int peoNum = peoples.size();
    //printf("%f\n", avge);
    printf("%.1f\n", avge/(60*peoNum));
    return 0;
}
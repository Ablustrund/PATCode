#include <bits/stdc++.h>
using namespace std;
int beginAddr, n, addr, tdata, nextAddr;
struct node
{
    int addr, tdata;
    node(int _addr = 0, int _data = 0){addr = _addr; tdata = _data;}
};
struct node temp[100010];
bool cmp(const node &a, const node &b) { return a.tdata < b.tdata; }
int main()
{
    scanf("%d%d", &n, &beginAddr);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &addr, &tdata, &nextAddr);
        temp[addr] = node(nextAddr, tdata);
    }
    vector<node> res;
    while(beginAddr != -1)
    {
        res.push_back(node(beginAddr, temp[beginAddr].tdata));
        beginAddr = temp[beginAddr].addr;
    }
    sort(res.begin(), res.end(), cmp);
    if(res.size() != 0) 
    {
        printf("%d %05d\n", res.size(), res[0].addr);
        for(int i = 0; i + 1 < res.size(); i++) printf("%05d %d %05d\n", res[i].addr, res[i].tdata, res[i + 1].addr);
        printf("%05d %d -1\n", res[res.size()-1].addr, res[res.size()-1].tdata);
    }
    else printf("0 -1\n");
    return 0;
}
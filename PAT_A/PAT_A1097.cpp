#include <bits/stdc++.h>
using namespace std;
int bea, n, ta, td, tn;
struct node
{
    int dat, nex;
};
struct node oriL[100010];
vector<struct node> res1, res2;
set<int> sett;
int main()
{
    scanf("%d%d", &bea, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &ta, &td, &tn);
        node tmp;
        tmp.dat = td, tmp.nex = tn;
        oriL[ta] = tmp;
    }
    while(bea != -1)
    {
        if(sett.find(abs(oriL[bea].dat)) == sett.end())
        {
            sett.insert(abs(oriL[bea].dat));
            node tmp;
            tmp.dat = oriL[bea].dat, tmp.nex = bea;
            res1.push_back(tmp);
        }
        else
        {
            node tmp;
            tmp.dat = oriL[bea].dat, tmp.nex = bea;
            res2.push_back(tmp);
        }
        bea = oriL[bea].nex;
    }
    for (int i = 0; i + 1 < res1.size(); i++)
    {
        printf("%05d %d %05d\n", res1[i].nex, res1[i].dat, res1[i + 1].nex);
    }
    if(res1.size() != 0)printf("%05d %d -1\n", res1[res1.size() - 1].nex, res1[res1.size() - 1].dat);
    for (int i = 0; i + 1 < res2.size(); i++)
    {
        printf("%05d %d %05d\n", res2[i].nex, res2[i].dat, res2[i + 1].nex);
    }
    if(res2.size() != 0)printf("%05d %d -1\n", res2[res2.size() - 1].nex, res2[res2.size() - 1].dat);
    return 0;
}
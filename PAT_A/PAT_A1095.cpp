#include <bits/stdc++.h>
using namespace std;
int n, k, h, m, s;
string t1, t2;
struct node
{
    string t;
    int tim, st;
};
vector<struct node> recs;
map<string, int> mapp, mapp2;
set<string> sett;
int tm[100010], resQ[100010];
vector<string> res;
int resT = -1;
bool cmp1(const struct node &a, const struct node &b)
{
    return a.tim < b.tim;
}
bool cmp2(const string &a, const string &b)
{
    return a < b;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        cin >> t1;
        scanf("%d:%d:%d", &h, &m, &s);
        cin >> t2;
        node tmp;
        tmp.t = t1, tmp.tim = h * 3600 + m * 60 + s;
        if(t2 == "in") tmp.st = 1;
        else tmp.st = -1;
        recs.push_back(tmp);
    }
    sort(recs.begin(), recs.end(), cmp1);
    for (int i = 0; i < recs.size(); i++)
    {
        if(recs[i].st == 1)
        {
            sett.insert(recs[i].t);
            mapp[recs[i].t] = recs[i].tim;
        }
        else if(recs[i].st == -1)
        {
            if(sett.find(recs[i].t) != sett.end())
            {
                mapp2[recs[i].t] += recs[i].tim - mapp[recs[i].t];
                int tmp1 = mapp2[recs[i].t];
                // if(mapp2.find(recs[i].t) != mapp2.end())
                // {
                //     mapp2[recs[i].t] += tmp1;
                // }
                // else mapp2[recs[i].t] = tmp1;
                if(tmp1 > resT)
                {
                    res.clear();
                    res.push_back(recs[i].t);
                    resT = tmp1;
                }
                else if(tmp1 == resT)
                {
                    res.push_back(recs[i].t);
                }
                tm[mapp[recs[i].t]]++;
                tm[recs[i].tim]--;
                sett.erase(recs[i].t);
            }
        }
    }
    int tmp1 = 0;
    for (int i = 0; i < 24 * 3600; i++)
    {
        tmp1 += tm[i];
        resQ[i] = tmp1;
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d:%d:%d", &h, &m, &s);
        tmp1 = h * 3600 + m * 60 + s;
        printf("%d\n", resQ[tmp1]);
    }
    sort(res.begin(), res.end(), cmp2);
    for(int i = 0; i < res.size(); i++)
    {
        if(i == 0) printf("%s", res[i].c_str());
        else printf(" %s", res[i].c_str());
    }
    printf(" %02d:%02d:%02d\n", resT / 3600, resT % 3600 / 60, resT % 60);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, hh, mm, ss, playingtime, haveVIP, k, m, temp1, countsRooms[110];
bool vipRooms[110];
struct node
{
    int arrive, playing, hhh, mmm, sss;
    node(int _arrive, int _playing, int _hhh, int _mmm, int _sss){arrive = _arrive; playing = _playing;hhh = _hhh; mmm = _mmm; sss = _sss;}
};
vector<node> ordinary, VIP, res;
bool cmp(const node &a, const node &b) { return a.arrive < b.arrive; }
bool cmpres(const node &a, const node &b) { return a.playing < b.playing; }
struct node2
{
    int endtime, id;
    node2(int _endtime, int _id){endtime = _endtime; id = _id;}
};
struct cmp2
{
    bool operator() (const node2 &a, const node2 &b)
    {
        if(a.endtime != b.endtime) return a.endtime > b.endtime;
        else return a.id > b.id;
    }
};
priority_queue<node2, vector<node2>, cmp2> q;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &playingtime, &haveVIP);
        int temp = hh * 3600 + mm * 60 + ss;
        int temp2 = playingtime / 60;
        playingtime = temp2 * 3600 + (playingtime % 60) * 60;
        if(playingtime > 7200) playingtime = 7200;
        if(haveVIP == 1) VIP.push_back(node(temp, playingtime, hh, mm, ss));
        else ordinary.push_back(node(temp, playingtime, hh, mm, ss));
    }
    sort(ordinary.begin(), ordinary.end(), cmp);
    sort(VIP.begin(), VIP.end(), cmp);
    VIP.push_back(node(999999, 999999, 999999, 999999, 999999));
    ordinary.push_back(node(999999, 999999, 999999, 999999, 999999));
    scanf("%d%d", &k, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp1);
        vipRooms[temp1] = true;
    }
    for (int i = 1; i <= k; i++) q.push(node2(8*3600, i));
    int indexO = 0, indexVIP = 0;
    for (int i = 0; i < n; i++)
    {
        int tempid = q.top().id;
        int temptime = q.top().endtime;
        if(temptime >= 75600) break;
        int tempp = min(VIP[indexVIP].arrive, ordinary[indexO].arrive);
        while(tempp > temptime)
        {
            q.pop();
            q.push(node2(tempp, tempid));
            tempid = q.top().id;
            temptime = q.top().endtime;
        }
        q.pop();
        if(vipRooms[tempid])
        {
            if(indexVIP < VIP.size() - 1 && temptime >= VIP[indexVIP].arrive)
            {
                res.push_back(node(VIP[indexVIP].arrive, temptime, VIP[indexVIP].hhh, VIP[indexVIP].mmm, VIP[indexVIP].sss));
                q.push(node2(temptime + VIP[indexVIP].playing, tempid));
                indexVIP++;

            }
            else
            {
                res.push_back(node(ordinary[indexO].arrive, temptime, ordinary[indexO].hhh, ordinary[indexO].mmm, ordinary[indexO].sss));
                q.push(node2(temptime + ordinary[indexO].playing, tempid));
                indexO++;
            }
        }
        else
        {
            if(VIP[indexVIP].arrive < ordinary[indexO].arrive)
            {
                res.push_back(node(VIP[indexVIP].arrive, temptime, VIP[indexVIP].hhh, VIP[indexVIP].mmm, VIP[indexVIP].sss));
                q.push(node2(temptime + VIP[indexVIP].playing, tempid));
                indexVIP++;
            }
            else
            {
                res.push_back(node(ordinary[indexO].arrive, temptime, ordinary[indexO].hhh, ordinary[indexO].mmm, ordinary[indexO].sss));
                q.push(node2(temptime + ordinary[indexO].playing, tempid));
                indexO++;
            }
        }
        countsRooms[tempid]++;
    }
    sort(res.begin(), res.end(), cmpres);
    for (int i = 0; i < res.size(); i++)
    {
        double tempd = (res[i].playing - res[i].arrive)/60.0 + 0.5;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", res[i].hhh, res[i].mmm, res[i].sss, res[i].playing / 3600, res[i].playing % 3600 / 60, res[i].playing % 60, (int)tempd);
    }
    for(int i = 1; i <= k; i++)
    {
        if(i == 1) printf("%d", countsRooms[i]);
        else printf(" %d", countsRooms[i]);
    }
        return 0;
}
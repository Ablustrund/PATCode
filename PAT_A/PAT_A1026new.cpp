#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int n, hour, minute, second, lasttime, tag, k, m;
bool isviproom[110];
int counts[110];
struct player
{
    int arrivetime, lasttime;
    player(int _arrivetime, int _lasttime){arrivetime = _arrivetime;lasttime = _lasttime;}
};
struct room
{
    int canusetime, id;
    room(int _canusetime, int _id){canusetime = _canusetime;id = _id;}
};
struct cmproom
{
    bool operator()(const room &a, const room &b){if (a.canusetime != b.canusetime) return a.canusetime > b.canusetime; else return a.id > b.id;}
};
bool cmpplayer(const player &a, const player &b) { return a.arrivetime < b.arrivetime; }
bool cmpres(const player &a, const player &b) { return a.lasttime < b.lasttime; }
vector<player> vip, ord;
vector<player> res;
priority_queue<room, vector<room>, cmproom> viproomqueue, ordroomqueue;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d %d\n", &hour, &minute, &second, &lasttime, &tag);
        if (lasttime > 120) lasttime = 120;
        if (tag == 1) vip.push_back(player(hour * 3600 + minute * 60 + second, lasttime * 60));
        else ord.push_back(player(hour * 3600 + minute * 60 + second, lasttime * 60));
    }
    scanf("%d%d", &k, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &tag);
        isviproom[tag] = true;
    }
    for (int i = 1; i <= k; i++)
    {
        if (isviproom[i]) viproomqueue.push(room(8 * 3600, i));
        else ordroomqueue.push(room(8 * 3600, i));
    }
    sort(vip.begin(), vip.end(), cmpplayer);
    sort(ord.begin(), ord.end(), cmpplayer);
    vip.push_back(player(inf, inf)); //插入尾部数据，避免溢出
    ord.push_back(player(inf, inf));
    viproomqueue.push(room(inf, inf));
    ordroomqueue.push(room(inf, inf));
    int indexordplayer = 0, indexvipplayer = 0;
    for (int i = 0; i < n; i++)
    {
        int updatetime = (vip[indexvipplayer].arrivetime < ord[indexordplayer].arrivetime) ? vip[indexvipplayer].arrivetime : ord[indexordplayer].arrivetime;
        int mincanuse, minisvip;
        if (viproomqueue.top().canusetime < ordroomqueue.top().canusetime)
        {
            mincanuse = viproomqueue.top().canusetime;
            minisvip = 1;
        }
        else
        {
            mincanuse = ordroomqueue.top().canusetime;
            minisvip = 0;
        }
        while (mincanuse < updatetime)
        {
            if (minisvip == 1)
            {
                int temp1 = viproomqueue.top().id;
                viproomqueue.pop();
                viproomqueue.push(room(updatetime, temp1));
            }
            else
            {
                int temp1 = ordroomqueue.top().id;
                ordroomqueue.pop();
                ordroomqueue.push(room(updatetime, temp1));
            }
            if (viproomqueue.top().canusetime < ordroomqueue.top().canusetime)
            {
                mincanuse = viproomqueue.top().canusetime;
                minisvip = 1;
            }
            else
            {
                mincanuse = ordroomqueue.top().canusetime;
                minisvip = 0;
            }
        }
        if (mincanuse >= 21 * 3600) break;
        if (vip[indexvipplayer].arrivetime < ord[indexordplayer].arrivetime)
        {
            //当前需要分配room的是一个vip: 有vip就分配vip，没有vip就分配普通房间(之前update操作保证了肯定存在房间)
            if (viproomqueue.top().canusetime <= ordroomqueue.top().canusetime)
            {
                res.push_back(player(vip[indexvipplayer].arrivetime, viproomqueue.top().canusetime));
                int temptime = viproomqueue.top().canusetime;
                int tempid = viproomqueue.top().id;
                viproomqueue.pop();
                viproomqueue.push(room(temptime + vip[indexvipplayer].lasttime, tempid));
                indexvipplayer++;
                counts[tempid]++;
            }
            else
            {
                res.push_back(player(vip[indexvipplayer].arrivetime, ordroomqueue.top().canusetime));
                int temptime = ordroomqueue.top().canusetime;
                int tempid = ordroomqueue.top().id;
                ordroomqueue.pop();
                ordroomqueue.push(room(temptime + vip[indexvipplayer].lasttime, tempid));
                indexvipplayer++;
                counts[tempid]++;
            }
        }
        else
        {
            if ((viproomqueue.top().canusetime < 21 * 3600) && vip[indexvipplayer].arrivetime <= viproomqueue.top().canusetime)
            {
                res.push_back(player(vip[indexvipplayer].arrivetime, viproomqueue.top().canusetime));
                int temptime = viproomqueue.top().canusetime;
                int tempid = viproomqueue.top().id;
                viproomqueue.pop();
                viproomqueue.push(room(temptime + vip[indexvipplayer].lasttime, tempid));
                indexvipplayer++;
                counts[tempid]++;
                continue;
            }
            //当分配的是一个普通人，直接分配最小usetime和最小的id的就行了
            if (viproomqueue.top().canusetime < ordroomqueue.top().canusetime || (viproomqueue.top().canusetime == ordroomqueue.top().canusetime && viproomqueue.top().id < ordroomqueue.top().id))
            {
                res.push_back(player(ord[indexordplayer].arrivetime, viproomqueue.top().canusetime));
                int temptime = viproomqueue.top().canusetime;
                int tempid = viproomqueue.top().id;
                viproomqueue.pop();
                viproomqueue.push(room(temptime + ord[indexordplayer].lasttime, tempid));
                indexordplayer++;
                counts[tempid]++;
            }
            else
            {
                res.push_back(player(ord[indexordplayer].arrivetime, ordroomqueue.top().canusetime));
                int temptime = ordroomqueue.top().canusetime;
                int tempid = ordroomqueue.top().id;
                ordroomqueue.pop();
                ordroomqueue.push(room(temptime + ord[indexordplayer].lasttime, tempid));
                indexordplayer++;
                counts[tempid]++;
            }
        }
    }
    sort(res.begin(), res.end(), cmpres);
    for (int i = 0; i < res.size(); i++) printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", res[i].arrivetime / 3600, res[i].arrivetime % 3600 / 60, res[i].arrivetime % 60, res[i].lasttime / 3600, res[i].lasttime % 3600 / 60, res[i].lasttime % 60, (res[i].lasttime - res[i].arrivetime + 30) / 60);
    for (int i = 1; i <= k; i++)
    {
        if (i == 1) printf("%d", counts[i]);
        else printf(" %d", counts[i]);
    }
    printf("\n");
    return 0;
}
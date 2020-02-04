#include <bits/stdc++.h>
using namespace std;
int n, m, k, q, temp, beginTime[30], cust[1010];
struct node
{
    int id, timee;
    node(int _id, int _timee){ id = _id; timee = _timee;}
};
struct cmp
{
        bool operator() (const node &a, const node &b)
    {
        if(a.timee != b.timee) return a.timee > b.timee;
        else return a.id > b.id;
    }
};
priority_queue<node, vector<node>, cmp> list2;
int main()
{
    fill(beginTime, beginTime + 30, 480);
    scanf("%d%d%d%d", &n, &m, &k, &q);
    queue<node> list1;
    for (int i = 0; i < m; i++) for (int j = 1; j <= n; j++) list1.push(node(j, 480));
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &temp);
        if(list1.size() != 0)
        {
            int id = list1.front().id;
            if(beginTime[id] >= 1020)
            {
                cust[i] = -1;
                list1.pop();
                continue;
            }
            cust[i] = beginTime[id] + temp;
            beginTime[id] = cust[i];
            list2.push(node(id, cust[i]));
            list1.pop();
        }
        else
        {
            if(list2.size() == 0)
            {
                cust[i] = -1;
                continue;
            }
            int id = list2.top().id;
            if(beginTime[id] >= 1020)
            {
                list2.pop();
                cust[i] = -1;
                continue;
            }
            cust[i] = beginTime[id] + temp;
            beginTime[id] = cust[i];
            list2.pop();
            list2.push(node(id, cust[i]));
        }
    }
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &temp);
        if(cust[temp] == -1) printf("Sorry\n");
        else printf("%02d:%02d\n", cust[temp] / 60, cust[temp] % 60);
    }
    return 0;
}
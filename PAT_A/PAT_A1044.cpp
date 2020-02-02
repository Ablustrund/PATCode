#include <bits/stdc++.h>
using namespace std;
int n, i, j, chain[100010], value, minn = 1000000000;
struct node
{
    int be, en, tot;
    node(int _be, int _en, int _tot) { be = _be; en = _en; tot = _tot;}
};
vector<node> res;
int main()
{
    scanf("%d%d", &n, &value);
    for(i = 1; i <= n; i++) scanf("%d", &chain[i]);
    j = i = 1;
    int preSum = 0;
    for(i = 1; i <= n; i++)
    {
        while(j <= n)
        {
            preSum += chain[j];
            if(preSum >= value)
            {
                if(minn > preSum) minn = preSum;
                if(preSum == minn) res.push_back(node(i, j, preSum));
                preSum -= (chain[i] + chain[j]);
                break;
            }
            else j++;
        }
    }
    for (int i = 0; i < res.size(); i++) if(res[i].tot == minn) printf("%d-%d\n", res[i].be, res[i].en);
    return 0;
}
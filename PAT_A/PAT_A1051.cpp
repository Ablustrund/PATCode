#include <bits/stdc++.h>
using namespace std;
int m, n, k, seq[1010];
bool flags = true;
int main()
{
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++) scanf("%d", &seq[j]);
        stack<int> sta;
        sta.push(1);
        flags = true;
        int nextPush = 2;
        for(int j = 0; j < n; j++)
        {
            if(sta.size()!= 0 && sta.top() > seq[j])
            {
                flags = false;
                printf("NO\n");
                break;
            }
            while((sta.size() == 0 || sta.top() != seq[j]) && nextPush <= n && sta.size() <= m) sta.push(nextPush++);
            if(sta.top() == n+1 || sta.size() > m)
            {
                flags = false;
                printf("NO\n");
                break;
            }
            sta.pop();
        }
        if(flags) printf("YES\n");
    }
    return 0;
}
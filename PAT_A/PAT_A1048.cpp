#include <bits/stdc++.h>
using namespace std;
int n, tot, temp;
int coinsNum[100010];//标明硬币temp有几个
vector<int> coins;
unordered_set<int> findit;
int main()
{
    scanf("%d%d", &n, &tot);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if(temp < tot)
        {
            coins.push_back(temp);
            coinsNum[temp]++;//硬币temp有几个。
            findit.insert(tot - temp);
        }
    }
    sort(coins.begin(), coins.end());
    for (int i = 0; i < coins.size(); i++)
    {
        if(findit.find(coins[i]) != findit.end())
        {
            if(2 * coins[i] == tot && coinsNum[coins[i]] == 1) continue;
            printf("%d %d\n", coins[i], tot - coins[i]);
            return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}

/*

#include <iostream>
using namespace std;
int a[1001];
int main() {
    int n, m, temp;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a[temp]++;
    }
    for(int i = 0; i < 1001; i++) {
        if(a[i]) {
            a[i]--;
            if(m > i && a[m-i]) {
                printf("%d %d", i, m - i);
                return 0;
            }
            a[i]++;
        }
    }
    printf("No Solution");
    return 0;
}

*/
#include <bits/stdc++.h>
using namespace std;
int N, M, K, temp, set1, set2, nc, nt;
unordered_set<int> sets[51];
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &M);
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &temp);
            sets[i].insert(temp);
        }
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++)
    {
        scanf("%d%d", &set1, &set2);
        nc = 0;
        for(auto&j:sets[set1]) if(sets[set2].find(j) != sets[set2].end()) nc++;
        nt = sets[set1].size() + sets[set2].size() - nc;
        printf("%.1f%\n", nc * 100.0 / nt);
    }
    return 0;
}
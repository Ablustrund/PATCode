#include <bits/stdc++.h>
using namespace std;
int np, ng, temp, level = 0, ranks[1010] = {0}, levelsNum[1010], fattest[1010];
vector<int> lists;
int main()
{
    scanf("%d%d", &np, &ng);
    for (int i = 0; i < np; i++) scanf("%d", &fattest[i]);
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &temp);
        lists.push_back(temp);
    }
    while(lists.size() != 1)
    {
        int j = 0;
        vector<int> temp;
        level++;
        for (int i = 0; i < lists.size(); i = j)
        {
            int maxx = -1, k;
            while(j < lists.size() && ( j == i || ((j - i) % ng != 0 && j != i)))
            {
                if(maxx < fattest[lists[j]])
                {
                    maxx = fattest[lists[j]];
                    k = lists[j];
                }
                j++;
            }
            temp.push_back(k);
            ranks[k] = level;
        }
        levelsNum[level] = temp.size();
        lists = temp;
    }
    for (int i = 0; i < np; i++)
    {
        if(i == 0) printf("%d", levelsNum[ranks[i]+1]+1);
        else printf(" %d", levelsNum[ranks[i]+1]+1);
    }
    printf("\n");
    return 0;
}
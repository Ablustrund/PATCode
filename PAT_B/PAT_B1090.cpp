#include <bits/stdc++.h>
using namespace std;
bool yesFlag = true;
int n, m, temp1, temp2;
vector<pair<int, int>> contra;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &temp1, &temp2);
        contra.push_back(make_pair(temp1, temp2));
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp1);
        yesFlag = true;
        set<int> sets;
        for (int j = 0; j < temp1; j++)
        {
            scanf("%d", &temp2);
            sets.insert(temp2);
        }
        for(auto&i:contra)
        {
            if(sets.find(i.first) != sets.end() && sets.find(i.second) != sets.end())
            {
                printf("No\n");
                yesFlag = false;
                break;
            }
        }
        if(yesFlag) printf("Yes\n");
    }
        return 0;
}
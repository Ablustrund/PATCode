#include <bits/stdc++.h>
using namespace std;
int n, m, k, temp1, temp2;
struct stu
{
    int id, ge, gi, tot;
};
vector<stu> stus;
int quota[110];
int choice[40010][5];
vector<int> res[110];
bool cmp(const struct stu &a, const struct stu &b)
{
    if(a.tot != b.tot) return a.tot > b.tot;
    else return a.ge > b.ge;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) scanf("%d", &quota[i]);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &temp1, &temp2);
        struct stu tempStu = {i, temp1, temp2, temp1 + temp2};
        stus.push_back(tempStu);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &choice[i][j]);
        }
    }
    sort(stus.begin(), stus.end(), cmp);
    int j = 0;
    for (int i = 0; i < n; i = j)
    {
        j = i + 1;
        while(j < n && stus[i].tot == stus[j].tot && stus[i].ge == stus[j].ge) j++;
        // sovle index from i inclusive to j exclusive
        stack<int> st;
        for (int ii = i; ii < j; ii++)
        {
            for (int kk = 0; kk < k; kk++)
            {
                if(quota[choice[stus[ii].id][kk]] > 0)
                {
                    res[choice[stus[ii].id][kk]].push_back(stus[ii].id);
                    st.push(choice[stus[ii].id][kk]);
                    break;
                }
            }
        }
        while(!st.empty())
        {
            quota[st.top()]--;
            st.pop();
        }
    }
    for (int i = 0; i < m; i++)
    {
        sort(res[i].begin(), res[i].end());
        for (int j = 0; j < res[i].size(); j++)
        {
            if(j == 0) printf("%d", res[i][j]);
            else printf(" %d", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
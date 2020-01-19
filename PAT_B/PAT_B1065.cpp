#include <bits/stdc++.h>
using namespace std;

int n, m, temp1, temp2;
bool married[100010], inParty[100010];
vector<pair<int, int>> vec;
vector<int> results;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &temp1, &temp2);
        vec.push_back(make_pair(temp1, temp2));
        married[temp1] = married[temp2] = true;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp1);
        inParty[temp1] = true;
        if(married[temp1] == false) results.push_back(temp1);
    }
    for(int i = 0; i < vec.size(); i++)
    {
        if((inParty[vec[i].first] && inParty[vec[i].second]) || !(inParty[vec[i].first] || inParty[vec[i].second])) continue;
        else
        {
            if(inParty[vec[i].first]) results.push_back(vec[i].first);
            if(inParty[vec[i].second]) results.push_back(vec[i].second);
        }
    }
    sort(results.begin(), results.end());
    printf("%d\n", results.size());
    for (int i = 0; i < results.size(); i++)
    {
        if(i == 0) printf("%05d", results[i]);
        else printf(" %05d", results[i]);
    }
    return 0;
}
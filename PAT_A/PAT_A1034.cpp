#include <bits/stdc++.h>
using namespace std;
int n, k, tempW, peopleNum = 0;
string tempU, tempV;
unordered_map<string, int> strtoint;
unordered_map<int, string> inttostr;
int graph[2010][2010], head[2010] = {0};
bool visitedNode[2010] = {false}, visitedEdge[2010][2010];
map<string, int> res;
void dfs(int v, int &totWeight, int &headofGang, int &maxWei, int &nums)
{
    if(visitedNode[v]) return;
    visitedNode[v] = true;
    nums++;
    if(head[v] > maxWei)
    {
        headofGang = v;
        maxWei = head[v];
    }
    for (int i = 0; i < peopleNum; i++)
    {
        if(graph[v][i] != 0 && !visitedEdge[v][i])
        {
            visitedEdge[v][i] = visitedEdge[i][v] = true;
            totWeight += graph[v][i];
        }
        if(graph[v][i] != 0 && !visitedNode[i]) dfs(i, totWeight, headofGang, maxWei, nums);
    }
    return;
}
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        cin >> tempU >> tempV >> tempW;
        if(strtoint.find(tempU) == strtoint.end())
        {
            strtoint[tempU] = peopleNum;
            inttostr[peopleNum++] = tempU;
        }
        if(strtoint.find(tempV) == strtoint.end())
        {
            strtoint[tempV] = peopleNum;
            inttostr[peopleNum++] = tempV;
        }
        graph[strtoint[tempU]][strtoint[tempV]] += tempW;
        graph[strtoint[tempV]][strtoint[tempU]] += tempW;
        head[strtoint[tempU]] += tempW;
        head[strtoint[tempV]] += tempW;
    }
    for (int i = 0; i < peopleNum; i++)
    {
        if (!visitedNode[i])
        {
            int totWeight = 0, headofgang = 0, maxWei = -1, nums = 0;
            dfs(i, totWeight, headofgang, maxWei, nums);
            if (totWeight > k && nums > 2)
            {
                res[inttostr[headofgang]] = nums;
            }
        }
    }
    printf("%d\n", res.size());
    for(auto&i:res) printf("%s %d\n", i.first.c_str(), i.second);
    return 0;
}
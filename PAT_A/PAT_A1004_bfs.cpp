#include <bits/stdc++.h>
using namespace std;
int n, m, tempRoot, tempK, tempChild;
vector<vector<int>> trees(110);
int level[110];
int main()
{
    scanf("%d%d", &n, &m);
    if(n == 1 && m == 0) {printf("1\n"); return 0;}
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &tempRoot, &tempK);
        for (int j = 0; j < tempK; j++)
        {
            scanf("%d", &tempChild);
            trees[tempRoot].push_back(tempChild);
            //level[tempChild] = level[tempRoot] + 1;!!!!!!!!!层次关系一定要在遍历的时候加（下面代码），因为有可能输入不是按照由根开始的顺序输入的
        }
    }
    queue<int> q;
    q.push(1);
    int counts = 0, preLevel = 0;
    while(!q.empty())
    {
        int tempNode = q.front();
        q.pop();
        if(preLevel != level[tempNode])
        {
            if(preLevel == 0) printf("%d", counts); 
            else printf(" %d", counts);
            counts = 0;
        }
        if(trees[tempNode].size() == 0) counts++;
        for (int i = 0; i < trees[tempNode].size(); i++)
        {
            q.push(trees[tempNode][i]);
            level[trees[tempNode][i]] = level[tempNode] + 1;//!!!!!!!!!层次关系一定要在遍历的时候加（这个位置），因为有可能输入不是按照由根开始的顺序输入的
        }
        preLevel = level[tempNode];
    }
    printf(" %d\n", counts);
    return 0;
}
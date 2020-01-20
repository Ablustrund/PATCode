#include <bits/stdc++.h>
using namespace std;

int beginAddr, nums, k, temp1, temp2, temp3;
unordered_map<int, pair<int, int>> nodeMap;//addr -> <index, addr>
struct node
{
    int index, addr;
    node(int _addr, int _index) {addr = _addr; index = _index; }
};
vector<node> vec;
int main()
{
    scanf("%d%d%d", &beginAddr, &nums, &k);
    for (int i = 0; i < nums; i++)
    {
        scanf("%d%d%d", &temp1, &temp2, &temp3);
        nodeMap[temp1] = make_pair(temp2, temp3);
    }
    while(beginAddr != -1)
    {
        vec.push_back(node(beginAddr, nodeMap[beginAddr].first));
        beginAddr = nodeMap[beginAddr].second;
    }
    for (int i = 0; i < vec.size() / k; i++)
    {
        int bias = i * k;
        for (int j = k - 1; j >= 1; j--)
        {
            printf("%05d %d %05d\n", vec[j+bias].addr, vec[j+bias].index, vec[j+bias - 1].addr);
        }
        if(i+1 == vec.size()/k)//此时处理的是最后一整块
        {
            if(vec.size() % k == 0)
            {
                printf("%05d %d -1\n", vec[bias].addr, vec[bias].index);
            }
            else
            {
                printf("%05d %d %05d\n", vec[bias+0].addr, vec[bias+0].index, vec[bias+k].addr);
                for (int j = bias + k; j < vec.size() - 1; j++)
                {
                    printf("%05d %d %05d\n", vec[j].addr, vec[j].index, vec[j+1].addr);
                }
                printf("%05d %d -1\n", vec[vec.size()-1].addr, vec[vec.size()-1].index);
            }
        }
        else
        {
            printf("%05d %d %05d\n", vec[bias].addr, vec[bias].index, vec[bias+2*k - 1].addr);
        }
    }
    return 0;
}
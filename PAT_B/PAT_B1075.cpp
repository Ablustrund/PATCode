#include <bits/stdc++.h>
using namespace std;

//通用方法：先存，然后按链表存放在vector中，然后处理。这个的处理方式位分为三个vector，然后合并。
int beginAddr, n, k, temp1, temp2, temp3;
map<int, pair<int, int>> originNode;//addr:<index, nextAddr>
struct node
{
    int addr, index;
    node(int _addr, int _index) { addr = _addr;  index = _index;}
};
vector<node> vec1, vec2, vec3;
int main()
{
    scanf("%d%d%d", &beginAddr, &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &temp1, &temp2, &temp3);
        originNode[temp1] = make_pair(temp2, temp3);
    }
    while(beginAddr != -1)
    {
        int tempIndex = originNode[beginAddr].first;
        if(tempIndex < 0) vec1.push_back(node(beginAddr, tempIndex));
        else if(tempIndex >= 0 && tempIndex <= k) vec2.push_back(node(beginAddr, tempIndex));
        else vec3.push_back(node(beginAddr, tempIndex));
        beginAddr = originNode[beginAddr].second;
    }
    for(int i = 0; i < vec2.size(); i++) vec1.push_back(vec2[i]);
    for(int i = 0; i < vec3.size(); i++) vec1.push_back(vec3[i]);
    for (int i = 0; i < vec1.size() - 1; i++) printf("%05d %d %05d\n", vec1[i].addr, vec1[i].index, vec1[i+1].addr);
    printf("%05d %d -1\n", vec1[vec1.size()-1].addr, vec1[vec1.size()-1].index);
    return 0;
}

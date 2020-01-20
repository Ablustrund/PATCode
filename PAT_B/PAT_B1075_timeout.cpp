#include <bits/stdc++.h>
using namespace std;

int beginAddr, n, k, temp1, temp2, temp3;
map<int, pair<int, int>> originNode;//addr:<index, nextAddr>
struct node
{
    int addr, index;
    node(int _addr, int _index) { addr = _addr;  index = _index;}
};
vector<node> vec;
void ins(vector<node> &vec, int &i, int &temp1)
{
    vec.insert(vec.begin() + temp1 + 1, node(vec[i].addr, vec[i].index));
    vec.erase(vec.begin() + i);
    temp1--;
}
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
        vec.push_back(node(beginAddr, originNode[beginAddr].first));
        beginAddr = originNode[beginAddr].second;
    }
    for (temp1 = vec.size() - 1; temp1 >= 0; temp1--) if(vec[temp1].index < 0) break;
    for (int i = temp1-1; i >= 0; i--) if(vec[i].index >= 0) ins(vec, i, temp1);
    for (temp2 = vec.size() - 1; temp2 > temp1; temp2--) if(vec[temp2].index >= 0 && vec[temp2].index <= k) break;
    for (int i = temp2-1; i > temp1; i--) if(vec[i].index > k) ins(vec, i, temp2);
    for (int i = 0; i < vec.size() - 1; i++) printf("%05d %d %05d\n", vec[i].addr, vec[i].index, vec[i + 1].addr);
    printf("%05d %d -1\n", vec[vec.size() - 1].addr, vec[vec.size() - 1].index);
    return 0;
}
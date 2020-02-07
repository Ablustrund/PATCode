#include <bits/stdc++.h>
using namespace std;
int n, beginAddr, tempaddr, tempdata, tempnext;
struct node
{
    int data = 0, address = 0;//propre: node's addr
    node(int _data = 0, int _address = 0) { data = _data; address = _address;}
};
struct node ori[100010];
vector<node> prepro;
int main()
{
    scanf("%d%d", &n, &beginAddr);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tempaddr, &tempdata, &tempnext);
        ori[tempaddr] = node(tempdata, tempnext);
    }
    while(beginAddr != -1)
    {
        prepro.push_back(node(ori[beginAddr].data, beginAddr));
        beginAddr = ori[beginAddr].address;
    }
    if(prepro.size() == 0)
    {
        printf("0 -1\n");
        return 0;
    }
    printf("%d %05d\n", prepro.size(), prepro[0].address);
    for(int i = 0; i < prepro.size() / 2; i++)
    {
        printf("%05d %d %05d\n", prepro[i].address, prepro[i].data, prepro[prepro.size() - 1 - i].address);
        if(i + 1 == prepro.size()/2 && prepro.size() % 2 == 0) break;
        printf("%05d %d %05d\n", prepro[prepro.size() - 1 - i].address, prepro[prepro.size() - 1 - i].data, prepro[i+1].address);
    }
    printf("%05d %d -1\n", prepro[prepro.size()/2].address, prepro[prepro.size()/2].data);
    return 0;
}
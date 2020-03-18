#include <bits/stdc++.h>
using namespace std;
int beginAddr, n, k, tempa, tempb, tempc;
struct node
{
    int addr, data, next;
    node(int _addr = -1, int _data = 0, int _next = -1) {addr = _addr; data = _data; next = _next;}
};
struct node tempMap[100010], orderedVec[100010], res[100010];

int main()
{
    scanf("%d%d%d", &beginAddr, &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tempa, &tempb, &tempc);
        tempMap[tempa] = node(tempa, tempb, tempc);
    }
    int theRealNodeNum = 0;
    int p = beginAddr;
    while(p != -1)
    {
        orderedVec[theRealNodeNum++] = tempMap[p];
        p = tempMap[p].next;
    }
    int jj = 0;
    for (int i = 0; i + k <= theRealNodeNum ; i += k)
    {
        for (int j = i + k - 1; j >= i; j--)
        {
            res[jj++] = orderedVec[j];
        }
    }
    for (;jj < theRealNodeNum; jj++) res[jj] = orderedVec[jj];
    
    for (int i = 0; i < theRealNodeNum - 1; i++) printf("%05d %d %05d\n", res[i].addr, res[i].data, res[i+1].addr);
    printf("%05d %d -1\n", res[theRealNodeNum-1].addr, res[theRealNodeNum-1].data);
    return 0;
}
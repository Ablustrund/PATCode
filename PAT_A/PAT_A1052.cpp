#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010

struct Node
{
    int addr = -1;
    int key;
    int next = -1;
    bool validatedNode = false;
} nodes[MAX];

bool cmp(Node a, Node b)
{
    if(a.validatedNode == false || b.validatedNode == false)
        return a.validatedNode > b.validatedNode;
    return a.key < b.key;
}

int main()
{
    int nodeNum, headAddr;
    int tempAddr, tempKey, tempNextAddr;

    scanf("%d%d", &nodeNum, &headAddr);
    for (int i = 0; i < nodeNum; i++)
    {
        scanf("%d%d%d", &tempAddr, &tempKey, &tempNextAddr);
        nodes[tempAddr].addr = tempAddr;
        nodes[tempAddr].key = tempKey;
        nodes[tempAddr].next = tempNextAddr;
    }
    int count = 0;
    int p = headAddr;
    while(p != -1)
    {
        nodes[p].validatedNode = true; //有效节点
        count++;
        p = nodes[p].next;
    }
    sort(nodes, nodes + MAX, cmp);
    int newHeadAddr = nodes[0].addr;
    for (int i = 0; i < count; i++)
    {
        nodes[i].next = nodes[i + 1].addr;
    }

    if(count == 0)
    {
        printf("0 -1\n");
        return 0;
    }
    printf("%d %05d\n", count, newHeadAddr);
    for (int i = 0; i < count - 1; i++)
    {
        printf("%05d %d %05d\n", nodes[i].addr, nodes[i].key, nodes[i].next);
    }
    printf("%05d %d -1\n", nodes[count - 1].addr, nodes[count - 1].key);
    return 0;
}
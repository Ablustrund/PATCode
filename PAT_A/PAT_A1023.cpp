#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    char data;
    int next;
    bool flag = false;
} node[100010];

int main()
{
    int word1, word2, nodeNum;
    int tempAddr, tempNextAddr;
    char tempWord;
    scanf("%d%d%d", &word1, &word2, &nodeNum);
    for (int i = 0; i < nodeNum; i++)
    {
        scanf("%d %c %d", &tempAddr, &tempWord, &tempNextAddr);
        node[tempAddr].data = tempWord;
        node[tempAddr].next = tempNextAddr;
    }
    int p = 0;
    for(p = word1; p != -1; p = node[p].next)
    {
        node[p].flag = true;
    }
    for (p = word2; p != -1; p = node[p].next)
    {
        if(node[p].flag == true)
        {
            printf("%05d\n", p);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
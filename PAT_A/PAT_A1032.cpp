#include <bits/stdc++.h>
using namespace std;
int word1Addr, word2Addr, n, tempAddr, tempNextAddr;
char tempData;
unordered_map<int, int> maps;
set<int> word1Set;
int main()
{
    scanf("%d%d%d", &word1Addr, &word2Addr, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &tempAddr, &tempData, &tempNextAddr);
        maps[tempAddr] = tempNextAddr;
    }
    tempAddr = word1Addr;
    while(tempAddr != -1)
    {
        word1Set.insert(tempAddr);
        tempAddr = maps[tempAddr];
    }
    tempAddr = word2Addr;
    while(tempAddr != -1)
    {
        if(word1Set.find(tempAddr) != word1Set.end()) break;
        tempAddr = maps[tempAddr];
    }
    if(tempAddr != -1) printf("%05d\n", tempAddr);
    else printf("-1\n");
    return 0;
}
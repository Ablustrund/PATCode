#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
int n, m;
int father[110];
set<int> root;
int findFather(int v)
{
    int a = v;
    while(v != father[v])
    {
        v = father[v];
    }
    while(a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = v;
    }
    return v;
}
//第二种写法
int findFather2(int v)
{
    if(v == father[v]) return v;
    else
    {
        int f = findFather2(father[v]);
        father[v] = f;
        return f;
    }
}

void fatherTogether(int a, int b)
{
    int tempF1 = findFather(a);
    int tempF2 = findFather(b);
    if(tempF1 == tempF2) return;
    father[tempF1] = tempF2;
}

int main()
{
    scanf("%d%d", &n, &m);
    int tempA, tempB;
    for (int i = 0; i < n; i++)
    {
        father[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &tempA, &tempB);
        fatherTogether(tempA, tempB);
    }
    for (int i = 0; i < n; i++)
    {
        root.insert(findFather(i));
    }
    cout << root.size() << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int arrays[100010];
bool tag[100010];
int maxx = -1, minn = 1000000010, m;
int main()
{
    fill(arrays, arrays + 100010, 0);
    fill(tag, tag + 100010, false);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &arrays[i]);
    maxx = arrays[0];
    for (int i = 1; i < m; i++)
    {
        if(maxx > arrays[i])
            tag[i] = true;
        else maxx = arrays[i];
    }
    minn = arrays[m - 1];
    for (int i = m - 1; i >= 0; i--)
    {
        if(minn < arrays[i])
            tag[i] = true;
        else minn = arrays[i];
    }
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < m; i++)
        if(tag[i] == false) q.push(arrays[i]);
    printf("%d\n", q.size());
    if(q.size() >= 1)
    {
        printf("%d", q.top());
        q.pop();
    }
    while(!q.empty())
    {
        printf(" %d", q.top());
        q.pop();
    }
    printf("\n");
    return 0;
}
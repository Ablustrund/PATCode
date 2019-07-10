#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int array[110];
vector<int> distinctNum;
set<int> path;

void judge(int a)
{
    while(a != 1)
    {
        if(a % 2 == 0)
        {
            a /= 2;
            path.insert(a);
        }
        else
        {
            a = (3 * a + 1)/2;
            path.insert(a);
        }
    }
}

int main()
{
    int count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    path.clear();
    for (int i = 0; i < n; i++)
    {
        judge(array[i]);
    }
    // for(auto&i:path)
    // {
    //     printf("%d ", i);
    // }
    // printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (path.find(array[i]) != path.end()) continue;
        else
        {
            distinctNum.push_back(array[i]);
            count++;
        }
    }
    sort(distinctNum.begin(), distinctNum.begin() + count);
    for (int i = distinctNum.size() - 1; i >= 0; i--)
    {
        if(i != 0) printf("%d ", distinctNum[i]);
        else printf("%d\n", distinctNum[i]);
    }
        return 0;
}
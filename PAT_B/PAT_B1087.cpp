#include <bits/stdc++.h>
using namespace std;

int n;
set<int> sets;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) sets.insert(i/2+i/3+i/5);
    printf("%d\n", sets.size());
    return 0;
}
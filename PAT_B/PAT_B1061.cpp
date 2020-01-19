#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, temp1, scores[110], rightWrong[110];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d", &scores[i]);
    for (int i = 0; i < m; i++) scanf("%d", &rightWrong[i]);
    for (int i = 0; i < n; i++)
    {
        int resultScore = 0;
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &temp1);
            if(temp1 == rightWrong[j]) resultScore += scores[j];
        }
        printf("%d\n", resultScore);
    }
        return 0;
}
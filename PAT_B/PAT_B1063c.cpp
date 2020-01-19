#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp1, temp2;
    double results = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &temp1, &temp2);
        if(results < sqrt(temp1*temp1 + temp2*temp2))
        {
            results = sqrt(temp1 * temp1 + temp2 * temp2);
        }
    }
    printf("%.2lf\n", results);
    return 0;
}
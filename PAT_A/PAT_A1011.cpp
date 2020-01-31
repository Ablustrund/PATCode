#include <bits/stdc++.h>
using namespace std;
int tempj;
double res = 1, temp1, temp2;
char arr[3] = {'W', 'T', 'L'};
int main()
{
    for (int i = 0; i < 3; i++)
    {
        temp2 = -1;
        for (int j = 0; j < 3; j++)
        {
            scanf("%lf", &temp1);
            if(temp2 < temp1) {temp2 = temp1; tempj = j;}
        }
        res *= temp2;
        if (i == 0) printf("%c", arr[tempj]);
        else printf(" %c", arr[tempj]);
    }
    res = (res * 0.65 - 1) * 2;
    printf(" %.2f\n", res);
    return 0;
}
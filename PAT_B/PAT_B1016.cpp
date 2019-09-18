#include <bits/stdc++.h>
using namespace std;

string strA, strB;
int a, b;
long long int pa = 0, pb = 0, aNums = 1, bNums = 1;
int main()
{
    cin >> strA >> a >> strB >> b;
    char A = '0' + a;
    char B = '0' + b;
    for (int i = 0; i < strA.size(); i++)
    {
        if(strA[i] == A)
        {
            pa += a * aNums;
            aNums *= 10;
        }
    }
    for (int i = 0; i < strB.size(); i++)
    {
        if(strB[i] == B)
        {
            pb += b * bNums;
            bNums *= 10;
        }
    }
    printf("%lld\n", pa + pb);
    return 0;
}
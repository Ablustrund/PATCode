#include <bits/stdc++.h>
using namespace std;

int gcd(int i, int j)
{
    while(i != j)
    {
        if(i < j) j = j - i;
        else i = i - j;
    }
    return i;
}

int main()
{
    int temp1, temp2, temp3, temp4, k;
    scanf("%d/%d %d/%d %d", &temp1, &temp2, &temp3, &temp4, &k);
    double double1 = 1.0 * temp1 * k / temp2;
    double double2 = 1.0 * temp3 * k / temp4;
    if(double1 > double2) swap(double1, double2);//深坑...
    //printf("%lf, %lf\n", double1, double2);
    bool firstPrint = true;
    for (int i = (int)double1+1; i < double2; i++)
    {
        if(gcd(i, k) == 1)
        {
            if(firstPrint)
            {
                printf("%d/%d", i, k);
                firstPrint = false;
            }
            else printf(" %d/%d", i, k);
        }
    }
    printf("\n");
    return 0;
}
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

struct factor
{
    int prime;
    int num;
} primeFactors[20];

long int N;
int primeNums = 0;

void finePrimeFactors(long int N)
{
    int m = sqrt(1.0 * N);
    for (int i = 2; i <= m; i++)
    {
        if(N % i == 0)
        {
            primeFactors[primeNums].prime = i;
            primeFactors[primeNums].num++;
            N /= i;
            while(N % i == 0)
            {
                primeFactors[primeNums].num++;
                N /= i;
            }
            primeNums++;
        }
    }
    if(N != 1)
    {
        primeFactors[primeNums].prime = N;
        primeFactors[primeNums].num++;
        primeNums++;
    }
}

int main()
{
    scanf("%ld", &N);
    if(N == 1)
    {
        printf("1=1\n");
        return 0;
    }
    finePrimeFactors(N);
    printf("%ld=", N);
    for (int i = 0; i < primeNums; i++)
    {
        if(primeFactors[i].num != 1) printf("%d^%d", primeFactors[i].prime, primeFactors[i].num);
        else printf("%d", primeFactors[i].prime);
        if(i != primeNums - 1) printf("*");
        else printf("\n");
    }
    return 0;
}
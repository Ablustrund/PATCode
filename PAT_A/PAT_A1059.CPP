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
            N = N / i;
            while(N % i == 0)
            {
                primeFactors[primeNums].num++;
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
    finePrimeFactors(N);
    printf("%ld=", N);
    for (int i = 0; i < primeNums; i++)
    {
        printf("%d^%d", primeFactors[i].prime, primeFactors[i].num);
        if(i != primeNums - 1) printf("*");
        else printf("\n");
    }
    return 0;
}
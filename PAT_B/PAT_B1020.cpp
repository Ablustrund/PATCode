#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct product
{
    double stocks = 0;
    double price = 0;
    double pricePerStock = 0;
} products[1010];

bool cmp(product a, product b)
{
    return a.pricePerStock > b.pricePerStock;
}

int main()
{
    int N;
    double D;
    double profitability = 0;
    scanf("%d %lf", &N, &D);
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &products[i].stocks);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &products[i].price);
        products[i].pricePerStock = (double)(products[i].price / products[i].stocks);
    }
    sort(products, products + N, cmp);
    for (int i = 0; i < N; i++)
    {
        if(products[i].stocks < D)
        {
            profitability += products[i].price;
            D -= products[i].stocks;
        }
        else
        {
            profitability += products[i].pricePerStock * D;
            break;
        }
    }
    printf("%.2lf\n", profitability);
    return 0;
}
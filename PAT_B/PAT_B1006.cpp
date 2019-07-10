#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int b = n / 100;
    n %= 100;
    int s = n / 10;
    n %= 10;
    for (int i = 0; i < b; i++) printf("B");
    for (int i = 0; i < s; i++) printf("S");
    for (int i = 1; i <= n; i++) printf("%d", i);
    printf("\n");
    return 0;
}
#include <stdio.h>

int n;
int circle;
int main()
{
    circle = 0;
    scanf("%d\n", &n);
    while(n != 1)
    {
        if(n % 2 == 0) n /= 2;
        else n = (3*n+1)/2;
        circle++;
    }
    printf("%d\n", circle);
    return 0;
}
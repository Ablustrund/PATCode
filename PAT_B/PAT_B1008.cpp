#include <stdio.h>

int main()
{
    int n, m;
    int array[110];
    scanf("%d%d", &n, &m);
    m %= n;
    for (int i = 0; i < n; i++) scanf("%d", &array[i]);
    for (int i = n - m; i < 2*n - m; i++)
    {
        if(i == 2*n - m -1) printf("%d\n", array[i%n]);
        else printf("%d ", array[i%n]);
    }
        return 0;
}
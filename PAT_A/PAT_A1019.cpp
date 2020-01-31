#include <bits/stdc++.h>
using namespace std;
long long int arr[110] = {0}, n, radix;
int indexx = 0;
bool isPali = true;
void toRadix(long long int n, long long int radix)
{
    while(n != 0)
    {
        arr[indexx++] = n % radix;
        n /= radix;
    }
    return;
}
int main()
{
    scanf("%lld%lld", &n, &radix);
    toRadix(n, radix);
    for (int i = 0; i < indexx/2; i++) if(arr[i] != arr[indexx-1 - i]) isPali = false;
    if(isPali) printf("Yes\n"); else printf("No\n");
    for (int i = indexx - 1; i >= 0; i--) if(i == indexx - 1) printf("%d", arr[i]); else printf(" %d", arr[i]);
    if(n == 0) printf("0");
    printf("\n");
    return 0;
}
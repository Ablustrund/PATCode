#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void print(long long int a, long long int b, bool sy)
{
    a = abs(a);
    long long int t = gcd(a, b);
    a /= t;
    b /= t;
    if(b == 0)
    {
        printf("Inf");
        return;
    }
    if(sy == 1) printf("(-");
    if(a % b == 0) printf("%lld", a / b);
    else if(a < b) printf("%lld/%lld", a, b);
    else printf("%lld %lld/%lld", a / b, a % b, b);
    if(sy == 1) printf(")");
    return;
}
int main()
{
    long long int a1, b1, a2, b2;
    bool sy1 = false, sy2 = false;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    if(a1 < 0) sy1 = true;
    if(a2 < 0) sy2 = true;
    long long int t = b1 * b2 / gcd(b1, b2);
    a1 = t / b1 * a1;
    a2 = t / b2 * a2;
    b1 = b2 = t;
    print(a1, b1, sy1);
    printf(" + ");
    print(a2, b2, sy2);
    printf(" = ");
    print(a1 + a2, b1, a1 + a2 > 0 ? 0 : 1);
    printf("\n");

    print(a1, b1, sy1);
    printf(" - ");
    print(a2, b2, sy2);
    printf(" = ");
    print(a1 - a2, b1, a1 - a2 > 0 ? 0 : 1);
    printf("\n");

    long long int temp2 = gcd(abs(a1), abs(b1));
    long long int temp3 = gcd(abs(a2), abs(b2));

    a1 /= temp2;
    b1 /= temp2;
    a2 /= temp3;
    b2 /= temp3;

    print(a1, b1, sy1);
    printf(" * ");
    print(a2, b2, sy2);
    printf(" = ");
    print(a1 * a2, b1 * b2, ((sy1 && sy2) || (!sy1 && !sy2))? 0 : 1);
    printf("\n");

    print(a1, b1, sy1);
    printf(" / ");
    print(a2, b2, sy2);
    printf(" = ");
    print(abs(a1 * b2), abs(a2 * b1), ((sy1 && sy2) || (!sy1 && !sy2))? 0 : 1);
    printf("\n");
    return 0;
}
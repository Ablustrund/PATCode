#include <bits/stdc++.h>
using namespace std;
int a = 1000000, b = 23428;
int gcd(int a, int b)
{
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}
int main()
{
    printf("gcd(a, b): %d\n", gcd(a, b));
    return 0;
}

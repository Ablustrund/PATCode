#include <bits/stdc++.h>
using namespace std;
int yourAb, x, y, temp1, i;
double temp2;
int main()
{
    scanf("%d%d%d", &yourAb, &x, &y);
    for (i = 99; i >= 10; i--)
    {
        temp1 = (i % 10) * 10 + i / 10;
        temp2 = 1.0 * temp1 / y;
        if(temp2 * x == abs(i - temp1)) break;
    }
    if(i == 9) printf("No Solution\n");
    else printf("%d %s %s %s\n", i, i == yourAb ? "Ping" : (i > yourAb ? "Cong" : "Gai"), temp1 == yourAb ? "Ping" : (temp1 > yourAb ? "Cong" : "Gai"), temp2 == yourAb ? "Ping" : (temp2 > yourAb ? "Cong" : "Gai"));
    return 0;
}
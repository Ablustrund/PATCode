#include <bits/stdc++.h>
using namespace std;

int c1, c2;
int main()
{
    scanf("%d%d", &c1, &c2);
    double T = (c2 - c1) / 100.0;
    int second = (T + 0.5) / 1;
    int hour = second / 3600;
    second %= 3600;
    int minute = second / 60;
    second %= 60;
    printf("%02d:%02d:%02d\n", hour, minute, second);
    return 0;
}
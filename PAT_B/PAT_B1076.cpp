#include <bits/stdc++.h>
using namespace std;

int n, wifiSec[110];
string tempStr;
int main()
{
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, tempStr);
        wifiSec[i] = tempStr[tempStr.find('T') - 2] - 'A' + 1;
    }
    for(int i = 0; i < n; i++) printf("%d", wifiSec[i]);
    printf("\n");
    return 0;
}   
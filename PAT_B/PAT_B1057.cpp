#include <bits/stdc++.h>
using namespace std;

long long int Sum = 0;
int main()
{
    string str;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z') Sum += str[i] - 'a' + 1;
        else if(str[i] >= 'A' && str[i] <= 'Z') Sum += str[i] - 'A' + 1;
    }
    int count1 = 0, count0 = 0;
    while(Sum != 0)
    {
        if(Sum % 2 == 1) count1++;
        else count0++;
        Sum /= 2;
    }
    printf("%d %d\n", count0, count1);
    return 0;
}
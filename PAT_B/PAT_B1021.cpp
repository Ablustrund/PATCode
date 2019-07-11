#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int num[10] = {0};
int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) num[str[i] -'0']++;
    for (int i = 0; i < 10; i++) if(num[i] != 0) printf("%d:%d\n", i, num[i]);
}
#include <bits/stdc++.h>
using namespace std;

int a, b, j;
int main()
{
    scanf("%d%d", &a, &b);
    string str = to_string(a * b);
    j = str.size() - 1;
    while(str.size() != 1 && str[j--] == '0') str.erase(str.size()-1);
    for (int i = str.size() - 1; i >= 0; i--) printf("%c", str[i]);
    printf("\n");
    return 0;
}
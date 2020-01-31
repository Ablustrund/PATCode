#include <bits/stdc++.h>
using namespace std;
int n1, n2, maxx = -1;
int main()
{
    string str;
    cin >> str;
    for (int i = 3; i <= str.size(); i++)
    {
        int temp = (str.size() + 2 - i) / 2;
        if(maxx < temp && temp <= i) maxx = temp;
    }
    n1 = maxx;
    n2 = str.size() + 2 - 2 * n1;
    for (int i = 0; i < n1 - 1; i++)
    {
        printf("%c", str[i]);
        for (int j = 0; j < n2-2; j++) printf(" ");
        printf("%c\n", str[str.size() - 1 - i]);
    }
    for (int i = n1 - 1; i < n1-1+n2; i++) printf("%c", str[i]);
    printf("\n");
    return 0;
}
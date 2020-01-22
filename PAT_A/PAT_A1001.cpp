#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    scanf("%d%d", &a, &b);
    c = a + b;
    string res = to_string(c);
    if(res[0] == '-'){printf("-"); res.erase(res.begin());}
    for (int i = 0; i < res.size(); i++)
    {
        if(i != 0 && (res.size()-i)%3==0) printf(",");
        printf("%c", res[i]);
    }
    printf("\n");
    return 0;
}
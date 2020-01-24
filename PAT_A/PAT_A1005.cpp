#include <bits/stdc++.h>
using namespace std;
char eng[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main()
{
    string str, res;
    cin >> str;
    int sums = 0;
    for(auto&i:str) sums += (i - '0');
    res = to_string(sums);
    for(int i = 0; i < res.size(); i++) if(i == 0) printf("%s", eng[res[i] - '0']); else printf(" %s", eng[res[i] - '0']);
    printf("\n");
    return 0;
}
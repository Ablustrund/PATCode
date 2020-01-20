#include <bits/stdc++.h>
using namespace std;
int d, n;
int main()
{
    scanf("%d%d", &d, &n);
    string str = "0";
    str[0] += d;
    for (int i = 0; i < n-1; i++)
    {
        string tempStr = "";
        int j = 0, k = 0;
        while(j < str.size())
        {
            while(k < str.size() && str[j] == str[k]) k++;
            tempStr += str[j] + to_string(k - j);
            j = k;
        }
        str = tempStr;
    }
    printf("%s\n", str.c_str());
    return 0;
}
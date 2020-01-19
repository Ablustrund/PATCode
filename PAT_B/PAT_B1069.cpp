#include <bits/stdc++.h>
using namespace std;

int m, n, s, k;
string str;
set<string> hadChecked;
int main()
{
    scanf("%d%d%d", &m, &n, &s);
    getchar();
    k = 1;
    for(int i = 1; i <= m; i++, k++)
    {
        getline(cin, str);
        if(k >= s && (k - s) % n == 0)
        {
            if(hadChecked.find(str) != hadChecked.end())
            {
                k--;
                continue;
            }
            else
            {
                printf("%s\n", str.c_str());
                hadChecked.insert(str);
            }
        }
    }
    if(hadChecked.size() == 0) printf("Keep going...\n");
    return 0;
}
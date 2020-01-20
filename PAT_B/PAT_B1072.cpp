#include <bits/stdc++.h>
using namespace std;

int n, m, temp1, temp2, stuCount = 0, thiCount = 0;
string str;
set<int> things;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp1);
        things.insert(temp1);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> str >> temp1;
        bool havIlliThi = false;
        for (int j = 0; j < temp1; j++)
        {
            scanf("%d", &temp2);
            if(things.find(temp2) != things.end())
            {
                if(!havIlliThi)
                {
                    havIlliThi = true;
                    printf("%s: ", str.c_str());
                    stuCount++;
                    printf("%04d", temp2);
                    thiCount++;
                    continue;
                }
                printf(" %04d", temp2);
                thiCount++;
            }
        }
        if(havIlliThi) printf("\n");
    }
    printf("%d %d\n", stuCount, thiCount);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, player[110];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &player[i]);
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)//i和j是狼
        {
            vector<bool> checkIt;
            for (int k = 1; k <= n; k++)
            {
                int checkWho = abs(player[k]);//k指派checkWho是狼还是人
                checkIt.push_back((player[k] > 0 && checkWho != i && checkWho != j) || (player[k] < 0 && (checkWho == i || checkWho == j)));
            }
            if((checkIt[i-1] == false && checkIt[j-1] == false) || (checkIt[i-1] == true && checkIt[j-1] == true)) continue;
            int counts = 0;
            for(int m = 0; m < checkIt.size(); m++) if(checkIt[m] == false) counts++;
            if(counts == 2 && (checkIt[i-1] == false || checkIt[j-1] == false))
            {
                printf("%d %d\n", i, j);
                return 0;
            }            
        }
    }
    printf("No Solution\n");
    return 0;
}
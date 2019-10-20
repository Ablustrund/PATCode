#include <bits/stdc++.h>
using namespace std;

char tempCh;
int chNums[6];
char indexx[6] = {'P', 'A', 'T', 'e', 's', 't'};
int maxx = -1;
int main()
{
    fill(chNums, chNums + 6, 0);
    while(~scanf("%c", &tempCh) && tempCh != '\n')
    {
        if(tempCh == 'P') chNums[0]++;
        else if(tempCh == 'A') chNums[1]++;
        else if(tempCh == 'T') chNums[2]++;
        else if(tempCh == 'e') chNums[3]++;
        else if(tempCh == 's') chNums[4]++;
        else if(tempCh == 't') chNums[5]++;
    }
    for (int i = 0; i < 6; i++)
        if(maxx < chNums[i]) maxx = chNums[i];
    for (int i = 0; i < maxx; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(chNums[j] > 0)
            {
                chNums[j]--;
                printf("%c", indexx[j]);
            }
        }
    }
    printf("\n");
    return 0;
}
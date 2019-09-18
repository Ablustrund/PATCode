#include <bits/stdc++.h>
using namespace std;

int n;
int aWin, aPing, aDefeat;
int bWin, bPing, bDefeat;
int maxx[2][3]; //maxx[0]-甲 布，锤子，剪刀-b, c, j
char tempA, tempB;
char types[3] = {'B', 'C', 'J'};
int main()
{
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        scanf("%c %c", &tempA, &tempB);
        getchar();
        if(tempA == tempB)
        {
            aPing++;
            bPing++;
        }
        else if(tempA == 'C' && tempB == 'J')
        {
            aWin++;
            bDefeat++;
            maxx[0][1]++;
        }
        else if(tempA == 'J' && tempB == 'C')
        {
            bWin++;
            aDefeat++;
            maxx[1][1]++;
        }
        else if(tempA == 'J' && tempB == 'B')
        {
            aWin++;
            bDefeat++;
            maxx[0][2]++;
        }
        else if(tempA == 'B' && tempB == 'J')
        {
            bWin++;
            aDefeat++;
            maxx[1][2]++;
        }
        else if(tempA == 'B' && tempB == 'C')
        {
            aWin++;
            bDefeat++;
            maxx[0][0]++;
        }
        else if(tempA == 'C' && tempB == 'B')
        {
            bWin++;
            aDefeat++;
            maxx[1][0]++;
        }
    }
    int k1, k2;
    int maxTemp = -1;
    for (int i = 0; i < 3; i++)
    {
        if(maxx[0][i] > maxTemp)
        {
            maxTemp = maxx[0][i];
            k1 = i;
        }
    }
    maxTemp = -1;
    for (int i = 0; i < 3; i++)
    {
        if(maxx[1][i] > maxTemp)
        {
            maxTemp = maxx[1][i];
            k2 = i;
        }
    }
    printf("%d %d %d\n%d %d %d\n%c %c\n", aWin, aPing, aDefeat, bWin, bPing, bDefeat, types[k1], types[k2]);
    return 0;
}
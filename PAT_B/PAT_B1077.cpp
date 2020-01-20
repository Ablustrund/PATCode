#include <bits/stdc++.h>
using namespace std;

int n, m, teaScore, tempScore, minScore, maxScore, tempCount;
double totalScore, tempTotScore;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        totalScore = tempTotScore = 0;
        minScore = m + 1;
        maxScore = -1;
        tempCount = 0;
        scanf("%d", &teaScore);
        for(int i = 1; i < n; i++)
        {
            scanf("%d", &tempScore);
            if(tempScore < 0 || tempScore > m) continue;
            tempTotScore += tempScore;
            tempCount++;
            if(tempScore < minScore) minScore = tempScore;
            if(tempScore > maxScore) maxScore = tempScore;
        }
        tempTotScore = 1.0 * (tempTotScore - minScore - maxScore) / (tempCount-2);
        totalScore = (tempTotScore + teaScore) / 2.0;
        //round(0, totalScore);
        printf("%d\n", (int)(totalScore + 0.5));
    }
    return 0;
}
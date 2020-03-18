#include <bits/stdc++.h>
using namespace std;
struct user
{
    int perfectItems, haveScore, score, id;
    int scores[10];
};
struct user users[50010];
int n, k, m, perfectScore[10], temp1, temp2, temp3;
bool cmp(const struct user &a, const struct user &b)
{
    if(a.haveScore != b.haveScore) return a.haveScore > b.haveScore;
    else if(a.score != b.score) return a.score > b.score;
    else if(a.perfectItems != b.perfectItems) return a.perfectItems > b.perfectItems;
    else return a.id < b.id;
}
int main()
{
    for (int i = 0; i < 10010; i++)
    {
        users[i].perfectItems = 0;
        users[i].haveScore = 0;
        users[i].score = 0;
        users[i].id = i;
        fill(users[i].scores, users[i].scores + 10, -2);
    }
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; i++) scanf("%d", &perfectScore[i]);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &temp1, &temp2, &temp3);
        if(temp3 != -1)
        {
            users[temp1].haveScore = 1;
            if(users[temp1].scores[temp2] != perfectScore[temp2] && temp3 == perfectScore[temp2])
            {
                users[temp1].perfectItems++;
            }
            if(users[temp1].scores[temp2] < 0)
            {
                users[temp1].score += temp3;
                users[temp1].scores[temp2] = temp3;
            }
            else if(temp3 > users[temp1].scores[temp2])
            {
                users[temp1].score = users[temp1].score - users[temp1].scores[temp2] + temp3;
                users[temp1].scores[temp2] = temp3;
            }
        }
        else if(temp3 == -1 && users[temp1].scores[temp2] == -2)
        {
            users[temp1].scores[temp2] = -1;
        }
    }
    sort(users, users + n + 1, cmp);
    int rank = 1, preScore = users[0].score, sameScoreNum = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if(users[i].haveScore == 0) break;
        if(users[i].score == preScore)
        {
            printf("%d ", rank);
            sameScoreNum++;
        }
        else
        {
            rank += sameScoreNum;
            sameScoreNum = 1;
            printf("%d ", rank);
        }
        preScore = users[i].score;
        printf("%05d %d", users[i].id, users[i].score);
        for (int j = 1; j <= k; j++)
        {
            if(users[i].scores[j] == -2) printf(" -");
            else if(users[i].scores[j] == -1) printf(" 0");
            else printf(" %d", users[i].scores[j]);
        }
        printf("\n");
    }
    return 0;
}
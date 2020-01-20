#include <bits/stdc++.h>
using namespace std;

int n, m, temp1, temp2, temp3;
char tempCh;
struct question
{
    int score, totNums, rigNums;
    bool tags[5] = {false};//选择了哪些正确的选项
    int worryNums[5] = {0};
    set<char> rigItems;
    question(int _score, int _totNums, int _rigNums, set<char> _rigItems)
    {
        score = _score;
        totNums = _totNums;
        rigNums = _rigNums;
        rigItems = _rigItems;
    }
};
vector<question> Quest;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &temp1, &temp2, &temp3);
        set<char> tempSet;
        for (int i = 0; i < temp3; i++)
        {
            getchar();
            scanf("%c", &tempCh);
            tempSet.insert(tempCh);
        }
        Quest.push_back(question(temp1, temp2, temp3, tempSet));
    }
    getchar();
    for (int i = 0; i < n; i++)
    {
        double totScore = 0;
        for (int j = 0; j < m; j++)
        {
            scanf("(%d", &temp1);
            bool noWorry = true;
            set<char> tempSet;
            fill(Quest[j].tags, Quest[j].tags + 5, false);
            for (int k = 0; k < temp1; k++)
            {
                getchar();
                scanf("%c", &tempCh);
                tempSet.insert(tempCh);
                if(Quest[j].rigItems.find(tempCh) == Quest[j].rigItems.end())
                {
                    noWorry = false;
                    Quest[j].worryNums[tempCh - 'a']++;
                }
                else Quest[j].tags[tempCh - 'a'] = true;
            }
            if(noWorry)
            {
                if(tempSet == Quest[j].rigItems) totScore += Quest[j].score;
                else totScore += Quest[j].score / 2.0;
            }
            for (int k = 0; k < Quest[j].totNums; k++)
            {
                if(Quest[j].tags[k] == false && Quest[j].rigItems.find(k+'a') != Quest[j].rigItems.end())
                {
                    Quest[j].worryNums[k]++;
                }
            }
            getchar();
            getchar();
        }
        printf("%.1lf\n", totScore);
    }
    int k = -1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < Quest[i].totNums; j++)
            if(Quest[i].worryNums[j] > k) k = Quest[i].worryNums[j];
    if(k == 0)
    {
        printf("Too simple\n");
        return 0;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < Quest[i].totNums; j++)
            if(k == Quest[i].worryNums[j]) printf("%d %d-%c\n", k, i + 1, j + 'a');     
    return 0;
}
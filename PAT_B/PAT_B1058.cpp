#include <bits/stdc++.h>
using namespace std;

int n, m, temp1, temp2, temp3;
char tempCh;
struct question
{
    int getScore, allNums, correctNums, errNums;
    set<char> items;
    question(int _getScore, int _allNums, int _correctNums, int _errNums, set<char> _items)
    {
        getScore = _getScore;
        allNums = _allNums;
        correctNums = _correctNums;
        errNums = _errNums;
        items = _items;
    }
};
vector<question> questionInfo;
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        set<char> tempVec;
        scanf("%d%d%d", &temp1, &temp2, &temp3);
        for (int j = 0; j < temp3; j++)
        {
            getchar();
            scanf("%c", &tempCh);
            tempVec.insert(tempCh);
        }
        questionInfo.push_back(question(temp1, temp2, temp3, 0, tempVec));
    }
    getchar();
    for (int i = 0; i < n; i++)
    {
        int stuScore = 0;
        for (int j = 0; j < m; j++)
        {
            getchar();//'('
            scanf("%d", &temp1);
            set<char> tempVec;
            for (int k = 0; k < temp1; k++)
            {
                getchar();
                scanf("%c", &tempCh);
                tempVec.insert(tempCh);
            }
            getchar();//')'
            if(tempVec == questionInfo[j].items) stuScore+=questionInfo[j].getScore;
            else questionInfo[j].errNums++;
            getchar();
        }
        printf("%d\n", stuScore);
    }
    temp1 = 0;
    for(auto&i:questionInfo)
        if(temp1 < i.errNums) temp1 = i.errNums;
    if(temp1 == 0) printf("Too simple\n");
    else
    {
        printf("%d", temp1);
        for (int i = 0; i < questionInfo.size(); i++)
        {
            if(temp1 == questionInfo[i].errNums) printf(" %d", i+1);
        }
        printf("\n");
    }
    return 0;
}
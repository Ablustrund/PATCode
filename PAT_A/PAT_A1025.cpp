#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
struct testee
{
	string testeeNum;
	int score;
	int group;

	int finalRank = 1;
	int localRank = 0;
} testees[30010];

int allNum = 0;
int groupNum;
int k;

bool cmp(testee a, testee b)
{
	if (a.score != b.score)
		return a.score > b.score;
	return a.testeeNum < b.testeeNum;
}

int main()
{
	scanf("%d", &groupNum);
	for (int i = 0; i < groupNum; i++)
	{
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			cin >> testees[allNum].testeeNum >> testees[allNum].score;
			testees[allNum].group = i + 1;
			allNum++;
		}
        sort(testees + allNum - k, testees + allNum, cmp);
        testees[allNum - k].localRank = 1;
        for (int j = allNum - k + 1; j < allNum; j++)
        {
            if(testees[j].score == testees[j - 1].score)
                testees[j].localRank = testees[j - 1].localRank;
            else
                testees[j].localRank = j - allNum + k + 1;
        }
    }
	sort(testees, testees + allNum, cmp);

	for (int i = 1; i < allNum; i++)
	{
		if (testees[i].score == testees[i - 1].score)
			testees[i].finalRank = testees[i - 1].finalRank;
		else
			testees[i].finalRank = i + 1;
	}

	// int localRankList[30010][3];//group, same score people numbers, score
	// for (int i = 0; i < allNum; i++)
	// {
	// 	localRankList[i][0] = 1;
	// 	localRankList[i][1] = 0;
	// 	localRankList[i][2] = -1;
	// }

	// for (int i = 0; i < allNum; i++)
	// {
	// 	if (localRankList[testees[i].group][2] == -1 || localRankList[testees[i].group][2] == testees[i].score)
	// 	{
	// 		if (localRankList[testees[i].group][2] == -1)
	// 			localRankList[testees[i].group][2] = testees[i].score;
	// 		testees[i].localRank = localRankList[testees[i].group][0];
	// 		localRankList[testees[i].group][1]++;
	// 	}
	// 	else
	// 	{
	// 		localRankList[testees[i].group][0] += localRankList[testees[i].group][1];
	// 		localRankList[testees[i].group][1] = 0;
	// 		localRankList[testees[i].group][2] = testees[i].score;
	// 		testees[i].localRank = localRankList[testees[i].group][0];
    //         localRankList[testees[i].group][1]++;
	// 	}
	// }
	printf("%d\n", allNum);
	for (int i = 0; i < allNum; i++)
	{
		cout << testees[i].testeeNum << ' ' << testees[i].finalRank << ' ' << testees[i].group << ' ' << testees[i].localRank << endl;
	}
	return 0;
}
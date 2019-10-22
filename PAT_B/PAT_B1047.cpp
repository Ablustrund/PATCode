#include <bits/stdc++.h>
using namespace std;

int n, tempScore, tempCode, tempPos, matesScore[1010];
bool tag[1010];
string tempStr, preStr;
int main()
{
    stringstream ss;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> tempStr >> tempScore;
        tempPos = tempStr.find("-");
        preStr = tempStr.substr(0, tempPos);
        ss << preStr;
        ss >> tempCode;
        ss.clear();
        ss.str("");
        matesScore[tempCode] += tempScore;
        tag[tempCode] = true;
    }
    tempScore = -1;
    int k;
    for (int i = 0; i < 1010; i++)
    {
        if(tag[i] && tempScore < matesScore[i])
        {
            tempScore = matesScore[i];
            k = i;
        }
    }
    printf("%d %d\n", k, tempScore);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void resolves(string &tempStr, vector<string> &tempVec)
{
    getline(cin, tempStr);
    //cout << tempStr << endl;
    int pos1 = tempStr.find('[');
    int pos2 = 0;
    while(pos1 != string::npos)
    {
        pos2 = tempStr.find(']');
        tempVec.push_back(tempStr.substr(pos1 + 1, pos2 - pos1  - 1));
        //cout << tempStr.substr(pos1 + 1, pos2 - pos1 - 1) << endl;
        tempStr.erase(0, pos2 + 1);
        pos1 = tempStr.find('[');
    }
}

int n, in1, in2, in3, in4, in5;
string outStr, tempHands, tempEyes, tempMouths;
vector<string> eyes, mouths, hands;
int main()
{
    resolves(tempHands, hands);
    resolves(tempEyes, eyes);
    resolves(tempMouths, mouths);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d%d", &in1, &in2, &in3, &in4, &in5);
        if(in1 > hands.size() || in5 > hands.size() || in2 > eyes.size() || in4 > eyes.size() || in3 > mouths.size())
        {
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        else if(in1 <= 0 || in2 <= 0 || in3 <= 0 || in4 <= 0 || in5 <= 0)//如果inX = 0，那么在后续操作中减1就有可能越界了。。
        {
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        else cout << hands[in1 - 1] << "(" << eyes[in2 - 1] << mouths[in3 - 1] << eyes[in4 - 1] << ")" << hands[in5 - 1] << endl;
    }
    return 0;
}
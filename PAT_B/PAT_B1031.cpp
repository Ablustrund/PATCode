#include <bits/stdc++.h>
using namespace std;

int n, tempNum, sumNums;
string str;
vector<string> unvalStr;
int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char indexx[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        sumNums = 0;
        for (int j = 0; j < 17; j++)
        {
            tempNum = str[j] - '0';
            sumNums += tempNum * weight[j];
        }
        sumNums %= 11;
        if(str[17] != indexx[sumNums]) unvalStr.push_back(str);
    }
    if(unvalStr.size() == 0) printf("All passed\n");
    else
    {
        for(auto&i:unvalStr)
        {
            cout << i << endl;
        }
    }
        return 0;
}
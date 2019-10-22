#include <bits/stdc++.h>
using namespace std;

int L, K;
long long int tempNum;
int flag = 0;
string tempStr;

bool isPrime(long long int temp)
{
    if(temp != 2 && temp % 2 == 0) return 0;
    double m = sqrt(temp);
    for (int i = 2; i <= m; i++)
    {
        if(temp % i == 0) return 0;
    }
    return 1;
}

int main()
{
    scanf("%d%d", &L, &K);
    string str;
    cin >> str;
    int len = str.length();
    for (int i = 0; i <= str.length() - K; i++)
    {
        //cout << i << " " << len - K << " " << str.length() << " " << str.length() - K << endl;
        tempStr = str.substr(i, K);
        tempNum = stoi(tempStr);
        if(isPrime(tempNum))
        {
            cout << tempStr << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0) printf("404\n");
    return 0;
}
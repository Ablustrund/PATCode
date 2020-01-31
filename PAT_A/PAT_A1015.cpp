#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    for (int i = 2; i <= sqrt(n) + 1; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}
string rev(string str)
{
    string res = "";
    for (int i = str.size()-1; i >= 0; i--) res+=str[i];
    return res;
}
string toRadix(string str, int sourRadix, int disRadix)
{
    int temp1 = 0, k = 1;
    for(int i = str.size()-1; i >= 0; i--)
    {
        temp1 += (str[i] - '0') * k;
        k *= sourRadix;
    }
    string res = "", tempStr = "0";
    while(temp1 != 0)
    {
        tempStr[0] = '0' + temp1 % disRadix;
        res = tempStr + res;
        temp1 /= disRadix;
    }
    return res;
}
int main()
{
    int n, d;
    while(1)
    {
        scanf("%d", &n);
        if(n < 0) break;
        scanf("%d", &d);
        string str = rev(toRadix(to_string(n), 10, d));
        if(isPrime(n) && isPrime(stoi(toRadix(str, d, 10)))) printf("Yes\n");
        else printf("No\n");
    }
}
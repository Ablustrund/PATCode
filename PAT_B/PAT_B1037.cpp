#include <bits/stdc++.h>
using namespace std;
string str1, str2;
struct money
{
    int galleon = 0, sickle = 0, knut = 0;
} p, a;
int strToInt(string str)
{
    int sum = 0, k = 1;
    for(int i = str.size()-1; i >= 0; i--)
    {
        sum += k * (str[i] - '0');
        k *= 10;
    }
    return sum;
}
void splllit(string &str1, struct money &a1)
{
    int pos = str1.find(".");
    string tempStr = str1.substr(0, pos);
    a1.galleon = strToInt(tempStr);
    str1.erase(0, pos + 1);
    pos = str1.find(".");
    tempStr = str1.substr(0, pos);
    a1.sickle = strToInt(tempStr);
    str1.erase(0, pos + 1);
    a1.knut = strToInt(str1);
}
int main()
{
    cin >> str1 >> str2;
    splllit(str1, p);
    splllit(str2, a);
    long long int allp = p.galleon * 17 * 29 + p.sickle * 29 + p.knut;
    long long int alla = a.galleon * 17 * 29 + a.sickle * 29 + a.knut;
    if(allp > alla)
    {
        printf("-");
        long long int temp = allp;
        allp = alla;
        alla = temp;
    }
    long long int charges = alla - allp;
    long long int chargesG = charges / (17 * 29);
    long long int chargesS = (charges - chargesG*(17*29)) / 29;
    printf("%lld.%lld.%lld\n", chargesG, chargesS, charges - chargesG * (17 * 29) - chargesS * 29);
    return 0;
}
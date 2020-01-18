#include <bits/stdc++.h>
using namespace std;

int n, numCount = 0;
double sums = 0, double1;
string str;

bool jundge(string str, double &outDouble)
{
    int dotTag = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(i == 0 && str[0] == '-') continue; 
        if(str[i] == '.') dotTag++;
        else if(str[i] < '0' || str[i] > '9') return false;
    }
    if(dotTag > 1) return false;
    if(dotTag == 1 && str.size() - str.find(".") - 1 > 2) return false;
    stringstream ss;
    double tempDouble;
    ss << str;
    ss >> tempDouble;
    if(tempDouble > 1000 || tempDouble < -1000) return false;
    outDouble = tempDouble;
    return true;
}

int main()
{
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if(!jundge(str, double1))
        {
            printf("ERROR: %s is not a legal number\n", str.c_str());
        }
        else
        {
            sums += double1;
            numCount++;
        }
    }
    if(numCount == 0) printf("The average of 0 numbers is Undefined\n");
    else if(numCount == 1) printf("The average of %d number is %.2lf\n", numCount, sums/numCount);
    else printf("The average of %d numbers is %.2lf\n", numCount, sums/numCount);
    return 0;
}
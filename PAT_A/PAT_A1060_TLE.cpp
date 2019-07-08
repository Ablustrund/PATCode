#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int N;
int flagA = 0, flagB = 0;
struct strings
{
    string str = "";
    int dotPos = 0;
} inputA, inputB;

void toDigitNum(strings &tempInput)
{
    int originalDotPos = 0;
    if(tempInput.str.find('.') == string::npos)
    {
        while(tempInput.str[0] == '0') tempInput.str.erase(0, 1);
        //tempInput.str = regex_replace(tempInput.str, reg, "");
        originalDotPos = tempInput.str.length();
    }
    else
    {
        while(tempInput.str[0] == '0') tempInput.str.erase(0, 1);
        //tempInput.str = regex_replace(tempInput.str, reg, "");
        if(tempInput.str[0] == '.')
        {
            tempInput.str.erase(0, 1);
            originalDotPos = 0;
            while(tempInput.str[0] == '0' || tempInput.str.length() == 0)
            {
                originalDotPos--;
                tempInput.str.erase(0, 1);
            }
            //tempInput.str.insert(tempInput.str.begin(), '0');
            //return;
        }
        else
        {
            originalDotPos = tempInput.str.find('.');
            tempInput.str.erase(originalDotPos, 1);
        }
    }
    tempInput.dotPos = originalDotPos;
    tempInput.str.insert(0, ".");
    tempInput.str.insert(0, "0");
}

void standardNum(string &tempStr)
{
    if(N > tempStr.length() - 2)
    {
        while(N > tempStr.length() - 2)
        {
            tempStr.push_back('0');
        }
    }
    if(N < tempStr.length() - 2)
    {
        tempStr.erase(tempStr.begin() + N + 2, tempStr.end());
    }
}

int main()
{
    cin >> N >> inputA.str >> inputB.str;
    if(inputA.str == "0") flagA = 1;
    if(inputB.str == "0") flagB = 1;
    toDigitNum(inputA);
    toDigitNum(inputB);
    standardNum(inputA.str);
    standardNum(inputB.str);
    if(inputA.str == inputB.str && inputA.dotPos == inputB.dotPos)
    {
        if(flagA == 1) printf("YES 0");  //cout << "YES 0" << endl;
        else printf("YES %s*10^%d\n", inputA.str.c_str(), inputA.dotPos);
        //cout << "YES" << " " << inputA.str << "*10^" << inputA.dotPos << endl;
    }
    else
    {
        if(flagA == 1) printf("NO 0 %s*10^%d\n", inputB.str.c_str(), inputB.dotPos);
        //cout << "NO" << " 0 " << inputB.str << "*10^" << inputB.dotPos << endl;
        else if(flagB == 1) printf("NO %s*10^%d 0\n", inputA.str.c_str(), inputA.dotPos);
        //cout << "NO" << " " << inputA.str << "*10^" << inputA.dotPos <<" 0 " << endl;
        else printf("NO %s*10^%d %s*10^%d\n", inputA.str.c_str(), inputA.dotPos, inputB.str.c_str(), inputB.dotPos);
        //cout << "NO" << " " << inputA.str << "*10^" << inputA.dotPos <<" " << inputB.str << "*10^" << inputB.dotPos << endl;
    }
    return 0;
}
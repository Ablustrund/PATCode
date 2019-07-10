#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sum = 0;
string s;
vector<int> output;
char word[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++) sum += (s[i] - '0');
    while(sum != 0)
    {
        output.push_back(sum % 10);
        sum /= 10;
    }
    for (int i = output.size() - 1; i >= 0; i--)
    {
        if(i != 0) printf("%s ", word[output[i]]);
        else printf("%s\n", word[output[i]]);
    }
        return 0;
}
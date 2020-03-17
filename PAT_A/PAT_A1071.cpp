#include <bits/stdc++.h>
using namespace std;

string str, res;
int resNum = -1;
unordered_map<string, int> counts;
int main()
{
    getline(cin, str);
    int j = 0;
    for (int i = 0; i < str.size(); i = j)
    {
        j = i;
        string word = "";
        while (j < str.size() && ((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '0' && str[j] <= '9')))
        {
            if(str[j] >= 'A' && str[j] <= 'Z') word.insert(word.end(), str[j] - 'A' + 'a');
            else word.insert(word.end(), str[j]);
            j++;
        }
        j++;
        if(word != "")
        {
            counts[word] += 1;
        }
    }
    for(auto&i:counts)
    {
        if(i.second > resNum)
        {
            res = i.first;
            resNum = i.second;
        }
        else if(i.second == resNum && i.first < res)
        {
            res = i.first;
        }
    }
    printf("%s %d\n", res.c_str(), resNum);
    return 0;
}
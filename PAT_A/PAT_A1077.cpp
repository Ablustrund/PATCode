#include <bits/stdc++.h>
using namespace std;
int n, minLength = 1000000000, flag = 0;
string str;
vector<char> resSuffix;
vector<string> sentences;
int main()
{
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        sentences.push_back(str);
        if(minLength > str.length()) minLength = str.length();
    }
    for (int i = 0; i < minLength; i++)
    {
        char ch = sentences[0][sentences[0].length() - i - 1];
        for(int j = 1; j < sentences.size(); j++)
        {
            if(sentences[j][sentences[j].length() - i - 1] != ch)
            {
                flag = 1;
                break;
            }
        }
        if(flag) break;
        resSuffix.push_back(ch);
    }
    if(resSuffix.size() == 0) printf("nai\n");
    else
    {
        for(int k = resSuffix.size() - 1; k >= 0; k--) printf("%c", resSuffix[k]);
        printf("\n");
    }
    return 0;
}
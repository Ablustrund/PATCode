#include <bits/stdc++.h>
using namespace std;

char ch;
string str, resultStr;
int main()
{
    //scanf("%c\n", &ch);
    scanf("%c", &ch);
    getchar();//为什么上面这样用就err
    getline(cin, str);
    if(ch == 'C')
    {
        int i = 0, k = 0, chCount = 0; 
        while(i < str.size())
        {
            chCount = 0;
            while(k < str.size() && str[i] == str[k])
            {
                chCount++;
                k++;
            }
            if(chCount == 1) printf("%c", str[i]);
            else printf("%d%c", chCount, str[i]);
            i = k;
        }
    }
    else if(ch == 'D')
    {
        int i = 0, indexs;
        while(i < str.size())
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                indexs = 0;
                while(i < str.size() && str[i] >= '0' && str[i] <= '9')
                {
                    indexs = indexs * 10 + str[i] - '0';
                    i++;
                }
                for (int j = 0; j < indexs; j++) printf("%c", str[i]);
            }
            else printf("%c", str[i]);
            i++;
        }
    }
    printf("\n");
    return 0;
}
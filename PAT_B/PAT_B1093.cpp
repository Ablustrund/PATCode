#include <bits/stdc++.h>
using namespace std;

bool visited[210] = {false};
string strA, strB;
int main()
{
    getline(cin, strA);
    getline(cin, strB);
    for (int i = 0; i < strA.length(); i++)
    {
        if(!visited[strA[i] - 0])
        {
            printf("%c", strA[i]);
            visited[strA[i] - 0] = true;
        }
    }
    for (int i = 0; i < strB.length(); i++)
    {
        if(!visited[strB[i] - 0])
        {
            printf("%c", strB[i]);
            visited[strB[i] - 0] = true;
        }
    }
    printf("\n");
    return 0;
}
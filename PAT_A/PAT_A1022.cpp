#include <bits/stdc++.h>
using namespace std;
int n, m;
string tempStr, tempId;
unordered_map<string, set<string>> dbBybookTitle, dbByAuthor, dbByKeyWord, dbByPublisher, dbByYear;
void formKeyWord(string id, string tempStr, unordered_map<string, set<string>> &db)
{
    int pos = tempStr.find(' ');
    while(pos != string::npos)
    {
        string str = tempStr.substr(0, pos);
        db[str].insert(id);
        tempStr.erase(0, pos+1);
        pos = tempStr.find(' ');
    }
    db[tempStr].insert(id);//这里差一点就忘了
    return;
}
void printRes(int funcId, string id)
{
    if(funcId == 1)
    {
        if(dbBybookTitle.find(id) == dbBybookTitle.end()) printf("Not Found\n");
        else for(auto&i:dbBybookTitle[id]) printf("%s\n", i.c_str());
    }
    else if(funcId == 2)
    {
        if(dbByAuthor.find(id) == dbByAuthor.end()) printf("Not Found\n");
        else for(auto&i:dbByAuthor[id]) printf("%s\n", i.c_str());
    }
    else if(funcId == 3)
    {
        if(dbByKeyWord.find(id) == dbByKeyWord.end()) printf("Not Found\n");
        else for(auto&i:dbByKeyWord[id]) printf("%s\n", i.c_str());
    }
    else if(funcId == 4)
    {
        if(dbByPublisher.find(id) == dbByPublisher.end()) printf("Not Found\n");
        else for(auto&i:dbByPublisher[id]) printf("%s\n", i.c_str());
    }
    else if(funcId == 5)
    {
        if(dbByYear.find(id) == dbByYear.end()) printf("Not Found\n");
        else for(auto&i:dbByYear[id]) printf("%s\n", i.c_str());
    }
}
int main()
{
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if(j == 1) {getline(cin, tempId); continue;}
            getline(cin, tempStr);
            if(j == 2) dbBybookTitle[tempStr].insert(tempId);
            else if(j == 3) dbByAuthor[tempStr].insert(tempId);
            else if (j == 4) formKeyWord(tempId, tempStr, dbByKeyWord);
            else if(j == 5) dbByPublisher[tempStr].insert(tempId);
            else if(j == 6) dbByYear[tempStr].insert(tempId);
        }
    }
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++)
    {
        getline(cin, tempStr);
        printf("%s\n", tempStr.c_str());
        int funcId = tempStr[0] - '0';
        tempStr.erase(0, 3);
        printRes(funcId, tempStr);
    }
    return 0;
}
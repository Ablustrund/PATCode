#include <bits/stdc++.h>
using namespace std;
int n, k, c, courseid;
string name;
vector<string>courses[2510];
bool cmp(const string &a, const string &b) { return a < b; }
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        cin >> name >> c;
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &courseid);
            courses[courseid].push_back(name);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        printf("%d %d\n", i, courses[i].size());
        sort(courses[i].begin(), courses[i].end(), cmp);
        for(auto&i:courses[i]) printf("%s\n", i.c_str());
    }
    return 0;
}

/*

可以加速

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
char name[40010][5];
vector<int> course[2510];
bool cmp1(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int cnt, temp;
        scanf("%s %d", name[i], &cnt);
        for(int j = 0; j < cnt; j++) {
            scanf("%d", &temp);
            course[temp].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp1);
        for(int j = 0; j < course[i].size(); j++)
            printf("%s\n", name[course[i][j]]);
    }
    return 0;
}
*/
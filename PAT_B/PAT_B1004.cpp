#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

struct student
{
    string name;
    string id;
    int score;
} students[1010];

bool cmp(struct student a, struct student b)
{
    return a.score > b.score;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> students[i].name >> students[i].id >> students[i].score;
    }
    sort(students, students + n, cmp);
    cout << students[0].name << " " << students[0].id << endl;
    cout << students[n-1].name << " " << students[n-1].id << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n, temp3, below, high;
string temp1, temp2;
struct stu
{
    string name, id;
    int grade;
    stu(string _name = "", string _id = "", int _grade = 0)
    {
        name = _name;
        id = _id;
        grade = _grade;
    }
};
vector<struct stu> temp, res;
bool cmp(const struct stu &a, const struct stu &b)
{
    return a.grade > b.grade;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        temp.push_back(stu(temp1, temp2, temp3));
    }
    scanf("%d%d", &below, &high);
    for (int i = 0; i < n; i++)
    {
        if(temp[i].grade >= below && temp[i].grade <= high) res.push_back(temp[i]);
    }
    sort(res.begin(), res.end(), cmp);
    for(int i = 0; i < res.size(); i++)
    {
        printf("%s %s\n", res[i].name.c_str(), res[i].id.c_str());
    }
    if(res.size() == 0) printf("NONE\n");
    return 0;
}
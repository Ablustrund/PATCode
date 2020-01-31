#include <bits/stdc++.h>
using namespace std;
int n, grade;
string name, gender, id;
struct stu
{
    string name, id;
    int grade;
    stu(string _name, string _id, int _grade) {name = _name; id = _id; grade = _grade;}
};
vector<stu> males, females;
bool cmp(const stu &a, const stu &b) { return a.grade > b.grade; }
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> name >> gender >> id >> grade;
        if(gender[0] == 'M') males.push_back(stu(name, id, grade));
        else females.push_back(stu(name, id, grade));
    }
    sort(males.begin(), males.end(), cmp);
    sort(females.begin(), females.end(), cmp);
    if(females.size() == 0) printf("Absent\n");
    else printf("%s %s\n", females[0].name.c_str(), females[0].id.c_str());
    if(males.size() == 0) printf("Absent\n");
    else printf("%s %s\n", males[males.size()-1].name.c_str(), males[males.size()-1].id.c_str());
    if(females.size() != 0 && males.size() != 0) printf("%d\n", females[0].grade - males[males.size()-1].grade);
    else printf("NA\n");
    return 0;
}
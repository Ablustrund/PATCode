#include <bits/stdc++.h>
using namespace std;
int n, k, age, worth, M, Amin, Amax, indexOfAge[210] = {0};
struct node
{
    string name;
    int age, worth;
    node(string _name, int _age, int _worth) { name = _name; age = _age; worth = _worth;}
};
vector<node> peoples, res;
bool cmp(const node &a, const node &b)
{
    if(a.worth != b.worth) return a.worth > b.worth;
    else if(a.age != b.age) return a.age < b.age;
    return a.name < b.name;
}
string name;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        cin >> name >> age >> worth;
        peoples.push_back(node(name, age, worth));
    }
    sort(peoples.begin(), peoples.end(), cmp);
    for(int i = 0; i < peoples.size(); i++)
    {
        if(indexOfAge[peoples[i].age] > 100) continue;
        indexOfAge[peoples[i].age]++;
        res.push_back(peoples[i]);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d", &M, &Amin, &Amax);
        int temp = M;
        printf("Case #%d:\n", i + 1);
        for (int j = 0; j < res.size() && temp > 0; j++)
        {
            if(res[j].age >= Amin && res[j].age <= Amax)
            {
                printf("%s %d %d\n", res[j].name.c_str(), res[j].age, res[j].worth);
                temp--;
            }
        }
        if(temp == M) printf("None\n");
    }
    return 0;
}
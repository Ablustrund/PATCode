#include <bits/stdc++.h>
using namespace std;

int n, temp1;
string tempStr1, tempStr2;
struct node
{
    double yi, jia, ding;
    int totalScore, stuNums;
    string id;
    node(double _yi = 0, double _jia = 0, double _ding = 0, int _totalScore = 0, int _stuNums = 0, string _id = ""){ yi = _yi; jia = _jia; ding = _ding; totalScore = _totalScore; stuNums = _stuNums; id = _id; }
};
unordered_map<string, node> maps;
vector<node> vec;
bool CMP(node a, node b)
{
    if(a.totalScore != b.totalScore) return a.totalScore > b.totalScore;
    else if(a.stuNums != b.stuNums) return a.stuNums < b.stuNums;
    return a.id < b.id;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> tempStr1 >> temp1 >> tempStr2;
        for(auto&i:tempStr2) if(i>='A' && i<='Z') i = i-'A'+'a';
        if(maps.find(tempStr2) == maps.end()) maps[tempStr2] = node(0, 0, 0, 0, 0, tempStr2);
        maps[tempStr2].stuNums++;
        if(tempStr1[0] == 'B') maps[tempStr2].yi += temp1;
        else if(tempStr1[0] == 'A') maps[tempStr2].jia += temp1;
        else maps[tempStr2].ding += temp1;
    }
    for(auto&i:maps)
    {
        i.second.totalScore = (int)(i.second.ding * 1.5 + i.second.jia + i.second.yi / 1.5);
        vec.push_back(node(0, 0, 0, i.second.totalScore, i.second.stuNums, i.first));
    }
    sort(vec.begin(), vec.end(), CMP);
    printf("%d\n", vec.size());
    int k = 0;
    for (int i = 0; i < vec.size(); i = k)
    {
        while(k < vec.size() && vec[i].totalScore == vec[k].totalScore)
        {
            printf("%d %s %d %d\n", i + 1, vec[k].id.c_str(), vec[k].totalScore, vec[k].stuNums);
            k++;
        }
    }
        return 0;
}
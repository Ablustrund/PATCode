#include <bits/stdc++.h>
using namespace std;

int p, m, n, tempScore;
string tempStr;
struct stu
{
    string ID;
    int gp, gmt, gf, g;
    stu(string _ID = "", int _gp = -1, int _gmt = -1, int _gf = -1, int _g = -1)
    {
        ID = _ID;
        gp = _gp;
        gmt = _gmt;
        gf = _gf;
        g = _g;
    }
};
unordered_map<string, stu> verified;
vector<stu> results;
bool CMP(stu a, stu b)
{
    if(a.g != b.g) return a.g > b.g;
    return a.ID < b.ID;
}
int main()
{
    scanf("%d%d%d", &p, &m, &n);
    for (int i = 0; i < p; i++)
    {
        cin >> tempStr >> tempScore;
        if(tempScore < 200) continue;
        verified[tempStr] = stu(tempStr, tempScore, -1, -1, 0);;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tempStr >> tempScore;
        if(verified.find(tempStr) != verified.end())
        {
            verified[tempStr].gmt = tempScore;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tempStr >> tempScore;
        if(verified.find(tempStr) != verified.end())
        {
            verified[tempStr].gf = tempScore;
        }
    }
    for(auto&i:verified)
    {
        if(i.second.gf == -1) continue;
        else if(i.second.gmt == -1)
        {
            if(i.second.gf >= 60)
            {
                i.second.g = i.second.gf;
                results.push_back(i.second);
            }
        }
        else
        {
            if(i.second.gmt > i.second.gf) i.second.g = (int)(0.4 * i.second.gmt + 0.6 * i.second.gf + 0.5);
            else i.second.g = i.second.gf;
            if(i.second.g >= 60) results.push_back(i.second);
        }
    }
    sort(results.begin(), results.end(), CMP);
    for(auto&i:results)
    {
        printf("%s %d %d %d %d\n", i.ID.c_str(), i.gp, i.gmt, i.gf, i.g);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, m, ch, tempSc;
string str;
char pat;
struct node1
{
    string stuId = "";
    int stuSc = 0;
    node1(string _stuId = "", int _stuSc = 0){ stuId = _stuId; stuSc = _stuSc; }
};
struct node3
{
    string ss;
    int nums;
    node3(string _ss = "", int _nums = 0) { ss = _ss; nums = _nums; }
};
vector<node1> BBB, AAA, TTT;
map<string, pair<int, int>> type2;//考场号-> <人数, 总分>
unordered_map<string, unordered_map<string, int>> type3;
bool CMP1(const node1 &a, const node1 &b){if(a.stuSc != b.stuSc) return a.stuSc > b.stuSc; return a.stuId < b.stuId;}
bool CMP2(const node3 &a, const node3 &b){if(a.nums != b.nums) return a.nums > b.nums; return a.ss < b.ss; }
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        cin >> str >> tempSc;
        if(str[0] == 'B') BBB.push_back(node1(str, tempSc));
        else if(str[0] == 'A') AAA.push_back(node1(str, tempSc));
        else TTT.push_back(node1(str, tempSc));
        string tempStr1 = str.substr(1, 3);
        if(type2.find(tempStr1) == type2.end()) type2[tempStr1] = make_pair(1, tempSc);
        else
        {
            type2[tempStr1].first++;
            type2[tempStr1].second += tempSc;
        }
        string tempStr2 = str.substr(4, 6);
        type3[tempStr2][tempStr1]++;
        }
    sort(BBB.begin(), BBB.end(), CMP1); sort(AAA.begin(), AAA.end(), CMP1); sort(TTT.begin(), TTT.end(), CMP1);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &ch);
        getchar();
        printf("Case %d: ", i);
        if(ch == 1)
        {
            scanf("%c", &pat);
            printf("1 %c\n", pat);
            if(pat == 'B' && BBB.size() != 0) for(auto&i:BBB) cout << i.stuId << " " << i.stuSc << endl;
            else if(pat == 'A' && AAA.size() != 0) for(auto&i:AAA) cout << i.stuId << " " << i.stuSc << endl;
            else if(pat == 'T' && TTT.size() != 0) for(auto&i:TTT) cout << i.stuId << " " << i.stuSc << endl;
            else printf("NA\n");
        }
        else if(ch == 2)
        {
            cin >> str;
            cout << "2 " << str << endl;
            if(type2.find(str) != type2.end()) cout << type2[str].first << " " << type2[str].second << endl;
            else printf("NA\n");
        }
        else
        {
            cin >> str;
            cout << "3 " << str << endl;
            vector<node3> vec;
            for(auto&i:type3[str]) vec.push_back(node3(i.first, i.second));
            if(vec.size() == 0)
            {
                printf("NA\n");
                continue;
            }
            sort(vec.begin(), vec.end(), CMP2);
            for(auto&i:vec) printf("%s %d\n", i.ss.c_str(), i.nums);
        }
    }
    return 0;
}
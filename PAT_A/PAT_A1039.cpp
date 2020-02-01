// method:1 300ms

// #include <bits/stdc++.h>
// using namespace std;
// int n, k, courseId, nums;
// string name;
// unordered_map<string, priority_queue<int, vector<int>, greater<int>>> querys;
// priority_queue<int, vector<int>, greater<int>> temp;
// int main()
// {
//     scanf("%d%d", &n, &k);
//     for (int i = 0; i < k; i++)
//     {
//         scanf("%d%d", &courseId, &nums);
//         getchar();
//         if(nums == 0) continue;
//         getline(cin, name);
//         int pos = name.find(' ');
//         while(pos != string::npos)
//         {
//             querys[name.substr(0, pos)].push(courseId);
//             name.erase(0, pos + 1);
//             pos = name.find(' ');
//         }
//         querys[name].push(courseId);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> name;
//         printf("%s %d", name.c_str(), querys[name].size());
//         temp = querys[name];
//         while(!temp.empty())
//         {
//             printf(" %d", temp.top());
//             temp.pop();
//         }
//         printf("\n");
//     }
//     return 0;
// }

// method:2  300ms

// #include <bits/stdc++.h>
// using namespace std;
// int n, k, courseId, nums;
// string name;
// struct cou
// {
//     int id;
//     string names;
//     cou(int _id, string _names) { id = _id; names = _names;}
// };
// vector<cou> courses;
// bool cmp(const cou &a, const cou &b) { return a.id < b.id; }
// unordered_map<string, vector<int>> querys;
// int main()
// {
//     scanf("%d%d", &n, &k);
//     for (int i = 0; i < k; i++)
//     {
//         scanf("%d%d", &courseId, &nums);
//         getchar();
//         if(nums == 0) continue;
//         getline(cin, name);
//         courses.push_back(cou(courseId, name));
//     }
//     sort(courses.begin(), courses.end(), cmp);
//     for(int i = 0; i < courses.size(); i++)
//     {
//         int pos = courses[i].names.find(' ');
//         while(pos != string::npos)
//         {
//             querys[courses[i].names.substr(0, pos)].push_back(courses[i].id);
//             courses[i].names.erase(0, pos + 1);
//             pos = courses[i].names.find(' ');
//         }
//         querys[courses[i].names].push_back(courses[i].id);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> name;
//         printf("%s %d", name.c_str(), querys[name].size());
//         for(auto&i:querys[name]) printf(" %d", i);
//         printf("\n");
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int n, k, courseId, nums;
// string name;
// unordered_map<string, priority_queue<int, vector<int>, greater<int>>> querys;
// priority_queue<int, vector<int>, greater<int>> temp;
// int main()
// {
//     scanf("%d%d", &n, &k);
//     for (int i = 0; i < k; i++)
//     {
//         scanf("%d%d", &courseId, &nums);
//         getchar();
//         if(nums == 0) continue;
//         getline(cin, name);
//         int pos = name.find(' ');
//         while(pos != string::npos)
//         {
//             querys[name.substr(0, pos)].push(courseId);
//             name.erase(0, pos + 1);
//             pos = name.find(' ');
//         }
//         querys[name].push(courseId);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> name;
//         printf("%s %d", name.c_str(), querys[name].size());
//         temp = querys[name];
//         while(!temp.empty())
//         {
//             printf(" %d", temp.top());
//             temp.pop();
//         }
//         printf("\n");
//     }
//     return 0;
// }


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int getid(char *name) {
    int id = 0;
    for(int i = 0; i < 3; i++)
        id = 26 * id + (name[i] - 'A');
    id = id * 10 + (name[3] - '0');
    return id;
}
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];

int main() {
    int n, k, no, num, id = 0;
    char name[5];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &no, &num);
        for(int j = 0; j < num; j++) {
            scanf("%s", name);
            id = getid(name);
            v[id].push_back(no);
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%s", name);
        id = getid(name);
        sort(v[id].begin(), v[id].end());
        printf("%s %lu", name, v[id].size());
        for(int j = 0; j < v[id].size(); j++)
            printf(" %d", v[id][j]);
        printf("\n");
    }
    return 0;
}
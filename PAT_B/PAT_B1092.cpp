#include <bits/stdc++.h>
using namespace std;
int n, m, temp;
struct types
{
    int num, id;
    types(int _num, int _id) { num = _num;  id = _id; }
};
vector<types> nums;
bool CMP(types a, types b)
{
    if(a.num != b.num) return a.num > b.num;
    return a.id < b.id;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &temp);
            if(i == 0) nums.push_back(types(temp, j+1));
            else nums[j].num += temp;
        }
    sort(nums.begin(), nums.end(), CMP);
    printf("%d\n%d", nums[0].num, nums[0].id);
    for (int i = 1; i < n && nums[i].num == nums[0].num; i++) printf(" %d", nums[i].id);
    printf("\n");
    return 0;
}
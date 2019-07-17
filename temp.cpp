#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, tempNum, maxCount = 0, maxNum = 0;
vector<pair<int, int>> nums;
vector<int> flag;
bool tag[500000000] = {false};
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        vector<int>::iterator j = find(flag.begin(), flag.end(), tempNum);
        if(tag[tempNum] == false)
        {
            nums.push_back(make_pair(tempNum, 1));
            flag.push_back(tempNum);
            tag[tempNum] = true;
        }
        else
        {
            nums[j - flag.begin()].second++;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i].second > maxCount){
            maxCount = nums[i].second;
            maxNum = nums[i].first;
        }
        else if(nums[i].second == maxCount && nums[i].first < maxNum) maxNum = nums[i].first;
    }
    printf("%d\n", maxNum);
        return 0;
}
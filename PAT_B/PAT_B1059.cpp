#include <bits/stdc++.h>
using namespace std;

int n, q, temp1;
unordered_map<int, pair<int, bool>> ranks;
bool jungle(int temp)
{
    if(temp == 2 || temp == 3) return true;
    else
    {
        for (int i = 2; i < sqrt(temp)+1; i++)
        {
            if(temp % i == 0) return false;
        }
    }
    return true;
    //     if (num == 2 || num == 3) //两个较小数另外处理
    //     return 1;
    // if (num % 6 != 1 && num % 6 != 5) //不在6的倍数两侧的一定不是质数
    //     return 0;
    // int tmp = sqrt(num);
    // for (int i = 5; i <= tmp; i += 6)           //在6的倍数两侧的也可能不是质数
    //     if (num % i == 0 || num % (i + 2) == 0) //排除所有，剩余的是质数
    //         return 0;
    // return 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp1);
        ranks[temp1] = make_pair(i + 1, false);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &temp1);
        printf("%04d: ", temp1);
        auto iter = ranks.find(temp1);
        if(iter == ranks.end()) printf("Are you kidding?\n");
        else if(ranks[temp1].second == true) printf("Checked\n");
        else if(ranks[temp1].first == 1)
        {
            printf("Mystery Award\n");
            ranks[temp1].second = true;
        }
        else if(jungle(ranks[temp1].first))
        {
            printf("Minion\n");
            ranks[temp1].second = true;
        }
        else
        {
            printf("Chocolate\n");
            ranks[temp1].second = true;
        }
    }
    return 0;
}
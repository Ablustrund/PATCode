#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    scanf("%d", &n);
    vector<int> ori(n), aim(n);
    for(int i = 0; i < n; i++) scanf("%d", &ori[i]);
    for(int i = 0; i < n; i++) scanf("%d", &aim[i]);
    
    vector<int> temp = ori;
    for(int i = 1; i < n; i++)
    {
        sort(temp.begin(), temp.begin() + i + 1);
        if(temp == aim)
        {
            printf("Insertion Sort\n");
            sort(temp.begin(), temp.begin() + i + 2);
            for(int j = 0; j < n; j++)
            {
                if(j == 0) printf("%d", temp[j]);
                else printf(" %d", temp[j]);
            }
            return 0;
        }
    }
    int k = 2;
    while(k <= n)
    {
        int i = 0;
        for (i = 0; i + k <= n; i += k)
        {
            sort(ori.begin() + i, ori.begin() + i + k);
        }
        if(i < n)
        {
            sort(ori.begin() + i, ori.begin() + n);
        }
        k *= 2;
        if(ori == aim)
        {
            printf("Merge Sort\n");
            for (i = 0; i + k <= n; i += k)
            {
                sort(ori.begin() + i, ori.begin() + i + k);
            }
            if(i < n)
            {
                sort(ori.begin() + i, ori.begin() + n);
            }
            for(int j = 0; j < n; j++)
            {
                if(j == 0) printf("%d", ori[j]);
                else printf(" %d", ori[j]);
            }
            return 0;
        }
    }

    return 0;
}
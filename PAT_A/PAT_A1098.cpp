#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> tmp2;
void downAdjust(int low, int high)
{
    int i = low, j = 2 * i;
    while(j <= high)
    {
        if(j + 1 <= high && tmp2[j + 1] > tmp2[j]) j = j + 1;
        if(tmp2[j] > tmp2[i])
        {
            swap(tmp2[j], tmp2[i]);
            i = j;
            j = 2 * i;
        }
        else break;
    }
    return;
}
int main()
{
    scanf("%d", &n);
    vector<int> ori(n), aim(n), tmp(n);
    for (int i = 0; i < n; i++) scanf("%d", &ori[i]);
    for (int i = 0; i < n; i++) scanf("%d", &aim[i]);
    tmp = ori;
    for (int i = 1; i < n; i++)
    {
        sort(tmp.begin(), tmp.begin() + i + 1);
        if(tmp == aim)
        {
            sort(tmp.begin(), tmp.begin() + i + 2);
            for(int j = 0; j < n; j++)
            {
                if(j == 0) printf("Insertion Sort\n%d", tmp[j]);
                else printf(" %d", tmp[j]);
            }
            return 0;
        }
    }
    aim.insert(aim.begin(), 0);
    tmp2.clear();
    tmp2.push_back(0);
    for(int i = 0; i < n; i++) tmp2.push_back(ori[i]);
    for (int i = n / 2; i >= 1; i--) downAdjust(i, n);
    for (int i = 1; i < n; i++)
    {
        if(aim == tmp2)
        {
            swap(tmp2[1], tmp2[n - i + 1]);
            downAdjust(1, n - i);
            for(int j = 1; j <= n; j++)
            {
                if(j == 1) printf("Heap Sort\n%d", tmp2[j]);
                else printf(" %d", tmp2[j]);
            }
        }
        swap(tmp2[1], tmp2[n - i + 1]);
        downAdjust(1, n - i);
    }
    return 0;
}
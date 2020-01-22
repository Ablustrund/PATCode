#include <bits/stdc++.h>
using namespace std;
int N, temp, m, n, graph[10010][10010];
vector<int> vec;
bool cmp(const int &a, const int &b) {return a > b;}
void getmn(int N, int &m, int &n)
{
    for (int i = (int)sqrt(N); i <= N; i++)
        if(N % i == 0)
        {
            m = max(i, N/i);
            n = N / m;
            return;
        }
}
int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), cmp);
    getmn(N, m, n);
    int bias = 0;
    int k = 0, j = 0, p = 0;
    for (int i = 0; i < m/2+1; i++)
    {
        p = bias;
        for (j = bias; j < n - bias; j++) graph[p][j] = vec[k++];
        if(k == vec.size()) break;
        p = n - bias - 1;
        for (j = bias+1; j < m - bias; j++) graph[j][p] = vec[k++];
        if(k == vec.size()) break;
        p = m - bias - 1;
        for(j = n-bias-2; j >= bias; j--) graph[p][j] = vec[k++];
        if(k == vec.size()) break;
        p = bias;
        for (j = m - bias - 2; j >= bias + 1; j--) graph[j][p] = vec[k++];
        if(k == vec.size()) break;
        bias++;
    }
    for (int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(j == 0) printf("%d", graph[i][j]); else printf(" %d", graph[i][j]);
    printf("\n");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, temp1, temp2;
double tempDouble;
priority_queue<double, vector<double>, greater<double>> pq;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &tempDouble);
        pq.push(tempDouble);
    }
    while(pq.size() != 1)
    {
        temp1 = pq.top();
        pq.pop();
        temp2 = pq.top();
        pq.pop();
        pq.push((temp1 + temp2) / 2.0);
    }
    printf("%.0f\n", pq.top());
    return 0;
}
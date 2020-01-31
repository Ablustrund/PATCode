#include <bits/stdc++.h>
using namespace std;
int n1, n2, index1 = 0, index2 = 0, counts = 0, bound;
long long int res, seq1[200010] = {0}, seq2[200010] = {0};
int main()
{
    scanf("%d", &n1);
    for(int i = 0; i < n1; i++) scanf("%lld", &seq1[i]);
    scanf("%d", &n2);
    for(int i = 0; i < n2; i++) scanf("%lld", &seq2[i]);
    bound = ((n1 + n2) % 2 == 0) ? (n1 + n2) / 2 : (n1 + n2) / 2 + 1;
    while(counts <= bound)
    {
        if(counts == bound) printf("%lld\n", res);
        if(index1 == n1) res = seq2[index2++];
        else if(index2 == n2) res = seq1[index1++];
        else if(seq1[index1] < seq2[index2]) res = seq1[index1++];
        else res = seq2[index2++];
        counts++;
    }
    return 0;
}
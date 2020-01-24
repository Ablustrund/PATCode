#include <bits/stdc++.h>
using namespace std;

int K, temp1, counts = 0;
double temp2, res[2010];
struct poly
{
    int exp;
    double coef;
    poly(int _exp = 0, double _coef = 0.0) { exp = _exp; coef = _coef;}
};
vector<poly> poly1, poly2;
int main()
{
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &K);
        for(int j = 0; j < K; j++)
        {
            scanf("%d%lf", &temp1, &temp2);
            if (i == 0) poly1.push_back(poly(temp1, temp2));
            else poly2.push_back(poly(temp1, temp2));
        }
    }
    for (int i = 0; i < poly1.size(); i++) for (int j = 0; j < poly2.size(); j++) res[poly1[i].exp + poly2[j].exp] += poly1[i].coef * poly2[j].coef;
    for (int i = 0; i < 2010; i++) if(res[i] != 0) counts++;
    printf("%d", counts);
    for (int i = 2009; i >= 0; i--) if(res[i] != 0) printf(" %d %.1f", i, res[i]);
    printf("\n");
    return 0;
}
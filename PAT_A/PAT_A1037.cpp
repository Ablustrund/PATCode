#include <bits/stdc++.h>
using namespace std;
//只能选择赚钱的组合，而不能选择任何赔钱的组合：(coupon > 0 and product > 0), (coupon < 0 and product < 0).
//coupon == 0 or product == 0的东西都不选
int nCoupon, nProduct;
long long int res, coupon[100010], product[100010];
int main()
{
    scanf("%d", &nCoupon);
    for(int i = 0; i < nCoupon; i++) scanf("%lld", &coupon[i]);
    scanf("%d", &nProduct);
    for(int i = 0; i < nProduct; i++) scanf("%lld", &product[i]);
    sort(coupon, coupon + nCoupon);
    sort(product, product + nProduct);
    for (int i = 0; i < min(nCoupon, nProduct); i++) if(coupon[i] < 0 && product[i] < 0) res += coupon[i] * product[i]; else break;
    for (int i = nCoupon-1, j = nProduct-1; i >= 0 && j >= 0; i--, j--) if(coupon[i] > 0 && product[j] > 0) res += coupon[i] * product[j]; else break;
    printf("%lld\n", res);
    return 0;
}
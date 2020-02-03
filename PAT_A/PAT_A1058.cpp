#include <bits/stdc++.h>
using namespace std;
int aGalleon, aSickle, aKnut, bGalleon, bSickle, bKnut, resG, resS, resK, carry;
int main()
{
    scanf("%d.%d.%d %d.%d.%d", &aGalleon, &aSickle, &aKnut, &bGalleon, &bSickle, &bKnut);
    resK = (aKnut + bKnut) % 29;
    carry = (aKnut + bKnut) / 29;
    resS = (aSickle + bSickle + carry) % 17;
    carry = (aSickle + bSickle + carry) / 17;
    resG = (aGalleon + bGalleon + carry);
    printf("%d.%d.%d\n", resG, resS, resK);
    return 0;
}
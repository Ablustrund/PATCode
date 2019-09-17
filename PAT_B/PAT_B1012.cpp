#include <bits/stdc++.h>
using namespace std;

int n, tempNum, case3Nums = 0;
long long int nums1 = 0, nums2 = 0, nums3 = 0, nums5 = 0;
double nums4 = 0;
bool case2Flag = 0;
bool flag[5] = {false};
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        switch(tempNum%5)
        {
            case 0:
                if(tempNum % 2 == 0)
                {
                    nums1 += tempNum;
                    flag[tempNum % 5] = 1;
                }
                break;
            case 1:
                if(case2Flag == 0)
                {
                    nums2 += tempNum;
                    flag[tempNum % 5] = 1;
                    case2Flag = 1;
                }
                else
                {
                    nums2 -= tempNum;
                    flag[tempNum % 5] = 1;
                    case2Flag = 0;
                }
                break;
            case 2:
                nums3++;
                flag[tempNum % 5] = 1;
                break;
            case 3:
                case3Nums++;
                flag[tempNum % 5] = 1;
                nums4 += tempNum;
                break;
            case 4:
                if(tempNum > nums5) nums5 = tempNum;
                flag[tempNum % 5] = 1;
                break;
        }
    }
    if(flag[0] == 1) printf("%lld", nums1);
    else printf("N");
    if(flag[1] == 1) printf(" %lld", nums2);
    else printf(" N");
    if(flag[2] == 1) printf(" %lld", nums3);
    else printf(" N");
    if(flag[3] == 1) printf(" %.1f", nums4/case3Nums);
    else printf(" N");
    if(flag[4] == 1) printf(" %lld\n", nums5);
    else printf(" N\n");
    return 0;
}
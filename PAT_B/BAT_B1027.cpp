#include <stdio.h>

int main()
{
    int nums;
    char ch;
    scanf("%d %c", &nums, &ch);
    int maxNums = 1;
    int k = 1;
    int i = 1;
    while(maxNums < nums)
    {
        k = 2 * i++ + 1;
        maxNums += 2*k;
    }
    if(maxNums > nums)
    {
        maxNums -= 2*k;
        k -= 2;
    }
    for (int j = k; j >= 1; j -= 2)
    {
        for (int m = 0; m < (k - j)/2; m++) printf(" ");
        for (int m = 0; m < j; m++) printf("%c", ch);
        printf("\n");
    }
    for (int j = 3; j <= k; j += 2)
    {
        for (int m = 0; m < (k - j)/2; m++) printf(" ");
        for (int m = 0; m < j; m++) printf("%c", ch);
        printf("\n");
    }
    printf("%d\n", nums - maxNums);
    return 0;
}
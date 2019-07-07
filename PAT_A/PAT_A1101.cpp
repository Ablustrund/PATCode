#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int n;
struct number
{
    int num = -1;
    bool tag = true;
} numbers[100010];
bool cmp(number a, number b)
{
    return a.num < b.num;
}
int main()
{
    scanf("%d", &n);
    int falseNum = 0;
    int leftMax = 0;
    int rightMin = 1000000001;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i].num);
        if(numbers[i].num < leftMax)
        {
            numbers[i].tag = false;
            falseNum++;
        }
        else
            leftMax = numbers[i].num;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if(numbers[i].num > rightMin)
        {
            if(numbers[i].tag == true) falseNum++;
            numbers[i].tag = false;
        }
        else rightMin = numbers[i].num;
    }
    sort(numbers, numbers + n, cmp);
    printf("%d\n", n - falseNum);
    bool firstOutput = true;
    for (int i = 0; i < n; i++)
    {
        if(numbers[i].tag == true)
        {
            if(firstOutput)
            {
                printf("%d", numbers[i].num);
                firstOutput = false;
            }
            else printf(" %d", numbers[i].num);
        }
    }
    printf("\n");
    return 0;
}
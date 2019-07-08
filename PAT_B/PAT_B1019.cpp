#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int array[4] = {0};

bool cmp(int a, int b)
{
    return a > b;
}

void toArray(int num)
{
    for(int i = 0; i < 4; i++)
    {
        array[i] = num%10;
        num /= 10;
    }
}
int toNum(int *array)
{
    int tempNum = 0;
    for (int i = 3; i >= 0; i--)
    {
        tempNum *= 10;
        tempNum += array[i];
    }
    return tempNum;
}

int initNum;
int main()
{
    scanf("%d", &initNum);
    int maxNum, minNum;
    while(1)
    {
        toArray(initNum);
        sort(array, array + 4);
        maxNum = toNum(array);
        sort(array, array + 4, cmp);
        minNum = toNum(array);
        initNum = maxNum - minNum;
        printf("%04d - %04d = %04d\n", maxNum, minNum, initNum);
        if(initNum == 6174 || initNum == 0)
            break;
    }
    return 0;
}
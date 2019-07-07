#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int text[10] = {0};
void outputFunc()
{
    for (int i = 0; i < 10; i++)
        while (text[i]--)
            printf("%d", i);
}

int main()
{
    for (int i = 0; i < 10; i++)
        scanf("%d", &text[i]);
    for (int i = 1; i < 10; i++)
        if (text[i])
        {
            printf("%d", i);
            text[i]--;
            outputFunc();
            break;
        }
    printf("\n");
    return 0;
}
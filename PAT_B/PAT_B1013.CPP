#include <stdio.h>
#include <algorithm>

using namespace std;
#define MAX 1000010
int primeArray[MAX];
int num = 0;
bool isNotPrime[MAX] = {false};

void findPrime(int n)
{
    for(int i = 2; i < MAX; i++)
    {
        if(isNotPrime[i] == false)
        {
            primeArray[num++] = i;
            if(num >= i) break;
            for(int j = i + i; j < MAX; j = j + i)
            {
                isNotPrime[j] = true;
            }
        }
    }
}

int main()
{
    int start, end, count = 0;
    scanf("%d%d", &start, &end);
    findPrime(end);
    for(int i = start - 1; i < end; i++)
    {
        printf("%d", primeArray[i]);
        if((++count % 10 != 0) &&(i != end - 1)) printf(" ");
        else printf("\n");
    }
    return 0;
}
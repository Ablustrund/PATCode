#include <bits/stdc++.h>
using namespace std;
int tempNum;
char arr[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
string toMarsColor(int num)
{
    string res = "";
    while(num != 0)
    {
        res.insert(res.begin(), arr[num % 13]);
        num /= 13;
    }
    if(res.size() == 0) res = "00";
    else if(res.size() == 1) res.insert(res.begin(), '0');
    return res;
}
int main()
{
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &tempNum);
        if(i == 0) printf("#");
        printf("%s", toMarsColor(tempNum).c_str());
    }
    printf("\n");
    return 0;
}
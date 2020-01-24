#include <bits/stdc++.h>
using namespace std;

string N1, N2, str;
long long int number1, number2, tag, radix;
long long int toDec(string str, int radix)
{
    long long int temp = 0, k = 1;
    for(int i = str.size()-1; i >= 0; i--)
    {
        if(str[i] >= '0' && str[i] <= '9') temp += (str[i] - '0') * k;
        else temp += (str[i] - 'a' + 10) * k;
        k *= radix;
    }
    return temp;
}
int main()
{
    cin >> N1 >> N2 >> tag >> radix;
    if(tag == 1) {number1 = toDec(N1, radix); str = N2;}
    else {number1 = toDec(N2, radix); str = N1;}
    auto it = max_element(str.begin(), str.end());
    long long int low = (isdigit(*it) ? *it - '0' : *it - 'a' + 10) + 1;
    long long int high = max(low, number1);//!!!!!!这里别忘了
    while(low <= high)
    {
        long long int mid = (low + high) / 2;
        number2 = toDec(str, mid);
        if(number2 > number1 || number2 < 0) high = mid - 1;
        else if(number2 < number1) low = mid + 1;
        else
        {
            printf("%lld\n", mid);
            return 0;
        }
    }

    printf("Impossible\n");
    return 0;
}
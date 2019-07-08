#include <iostream>
#include <string>
using namespace std;

int n;
string deal(string s, int &e)
{
    int k = 0; //s的下标
    while(s.length() > 0 && s[0] == '0') s.erase(s.begin()); // 去掉前导0
    if(s[0] == '.')
    {
        s.erase(s.begin());
        while(s.length() > 0 && s[0] == '0')
        {
            s.erase(s.begin());
            e--; //s的阶--
        }
    }
    else
    {
        if(s.find(".") == string::npos) e += s.length();
        else
        {
            k =  s.find(".");
             += k;
            s.erase(k, 1);
        }
/*         while(k < s.length() && s[k] != '.')
        {
            k++; //寻找小数点的下标
            e++;
        }
        if(k < s.length()) s.erase(s.begin() + k); //把小数点删掉，如果k == s.length()说明是整数没有小数点 */
    }
    if(s.length() == 0) e = 0;
    int num = 0;
    k = 0;
    string res;
    while(num < n)
    {
        if(k < s.length()) res += s[k++];
        else res += '0';
        num++;
    }
    return res;
}
int main()
{
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if(s3 == s4 && e1 == e2) cout << "YES 0." << s3 << "*10^" << e1 << endl;
    else cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
    return 0;
}
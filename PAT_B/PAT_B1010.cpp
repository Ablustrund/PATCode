#include <iostream>
using namespace std;

bool flag = true;
int main()
{
    int c, e;
    while(cin >> c >> e)
    {
        if(e != 0)
        {
            if(flag == false) cout << " ";
            else flag = false;
            cout << c*e << " " << e-1;
        }
    }
    if(flag) cout << "0 0";
    cout << endl;
    return 0;
}
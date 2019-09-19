#include <bits/stdc++.h>
using namespace std;

int n, k, tempValue;
string firstAddr, tempAddr, tempNext;
struct node
{
    string nowAddr;
    int value;
    string nextAddr;
    node(string _nowAddr = "", int _value = 0, string _nextAddr = "")
    {
        nowAddr = _nowAddr;
        value = _value;
        nextAddr = _nextAddr;
    }
};
map<string, node> link;
vector<string> nodeAddr;
int main()
{
    cin >> firstAddr >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> tempAddr >> tempValue >> tempNext;
        link[tempAddr] = node(tempAddr, tempValue, tempNext);
    }
    for (int i = 0; i < n; i++)
    {
        if(i && i % k == 0)
        {
            for (int j = k - 1; j >= 0; j--)
            {
                if(j == 0) cout << nodeAddr[j] << " " << link[nodeAddr[j]].value << " " << link[nodeAddr[k-1]].nextAddr << endl;
                else
                {
                    cout << nodeAddr[j] << " " << link[nodeAddr[j]].value << " " << link[nodeAddr[j-1]].nowAddr << endl;
                }
            }
            nodeAddr.clear();
        }
        nodeAddr.push_back(firstAddr);
        firstAddr = link[firstAddr].nextAddr;
    }
    if (nodeAddr.size() == k)
    {
        for (int j = k - 1; j >= 0; j--)
        {
            if (j == 0)
                cout << nodeAddr[j] << " " << link[nodeAddr[j]].value << " " << link[nodeAddr[k - 1]].nextAddr << endl;
            else
            {
                cout << nodeAddr[j] << " " << link[nodeAddr[j]].value << " " << link[nodeAddr[j - 1]].nowAddr << endl;
            }
        }
    }
    else if(nodeAddr.size() != 0)
    {
        for(int i = 0; i < nodeAddr.size(); i++)
        {
            cout << nodeAddr[i] << " " << link[nodeAddr[i]].value << " " << link[nodeAddr[i]].nextAddr << endl;
        }
    }
        return 0;
}
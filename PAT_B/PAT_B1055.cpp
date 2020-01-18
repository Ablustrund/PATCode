#include <bits/stdc++.h>
using namespace std;

int n, k, inHeight;
string inName;
struct student
{
    string stuName;
    int stuHeight;
    student(string _stuName, int _stuHeight)
    {
        stuName = _stuName;
        stuHeight = _stuHeight;
    }
};
vector<student> vec;
vector<vector<string> > results;
bool CMP(student a, student b)
{
    if (a.stuHeight != b.stuHeight)
        return a.stuHeight < b.stuHeight;
    return a.stuName > b.stuName;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        cin >> inName >> inHeight;
        vec.push_back(student(inName, inHeight));
    }
    sort(vec.begin(), vec.end(), CMP);
    int bias = 0;
    int q = 0;
    for (int i = 0; i < k - 1; i++)
    {
        vector<string> tempVec;
        if ((n / k) % 2 == 1)
        {
            q = 1;
            for (int j = 0; j < (n / k) / 2; j++)
            {
                tempVec.push_back(vec[bias + q].stuName);
                q += 2;
            }
            tempVec.push_back(vec[bias + n / k - 1].stuName);
            q = bias + n / k - 3;
            for (int j = 0; j < (n / k) / 2; j++)
            {
                tempVec.push_back(vec[q].stuName);
                q -= 2;
            }
        }
        else
        {
            q = 0;
            for (int j = 0; j < (n / k) / 2; j++)
            {
                tempVec.push_back(vec[bias + q].stuName);
                q += 2;
            }
            tempVec.push_back(vec[bias + n / k - 1].stuName);
            q = bias + n / k - 3;
            for (int j = 0; j < (n / k) / 2 - 1; j++)
            {
                tempVec.push_back(vec[q].stuName);
                q -= 2;
            }
        }
        results.push_back(tempVec);
        bias += n / k;
    }
    vector<string> tempVec;
    if ((n - bias) % 2 == 1)
    {
        q = 1;
        for (int j = 0; j < (n - bias) / 2; j++)
        {
            tempVec.push_back(vec[bias + q].stuName);
            q += 2;
        }
        tempVec.push_back(vec[n - 1].stuName);
        q = n - 3;
        for (int j = 0; j < (n - bias) / 2; j++)
        {
            tempVec.push_back(vec[q].stuName);
            q -= 2;
        }
    }
    else
    {
        q = 0;
        for (int j = 0; j < (n - bias) / 2; j++)
        {
            tempVec.push_back(vec[bias + q].stuName);
            q += 2;
        }
        tempVec.push_back(vec[n - 1].stuName);
        q = n - 3;
        for (int j = 0; j < (n - bias) / 2 - 1; j++)
        {
            tempVec.push_back(vec[q].stuName);
            q -= 2;
        }
    }
    results.push_back(tempVec);
    for (int i = results.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < results[i].size(); j++)
        {
            if(j == 0) printf("%s", results[i][j].c_str());
            else printf(" %s", results[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}
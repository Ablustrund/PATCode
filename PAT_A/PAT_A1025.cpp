#include <bits/stdc++.h>
using namespace std;
string tempId;
int n, k, tempSc;
struct testee
{
	string id;
	int sc, group, localRank;
	testee(string _id = "", int _sc = 0, int _group = 0, int _localRank = 0) { id = _id; sc = _sc; group = _group; localRank = _localRank;}
};
vector<testee> testees[110], res;
bool cmp(const testee &a, const testee &b){if(a.sc != b.sc) return a.sc > b.sc; return a.id < b.id;}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			cin >> tempId >> tempSc;
			testees[i].push_back(testee(tempId, tempSc, i, 0));
		}
		sort(testees[i].begin(), testees[i].end(), cmp);
		for (int j = 0, k = 0; j < testees[i].size(); j = k)
		{
			while(k < testees[i].size() && testees[i][j].sc == testees[i][k].sc)
			{
				testees[i][k].localRank = j + 1;
				k++;
			}
		}
		for(auto&j:testees[i]) res.push_back(j);
	}
	sort(res.begin(), res.end(), cmp);
	printf("%d\n", res.size());
	for (int i = 0, k = 0; i < res.size(); i = k)
	{
		while(k < res.size() && res[i].sc == res[k].sc)
		{
			printf("%s %d %d %d\n", res[k].id.c_str(), i + 1, res[k].group, res[k].localRank);
			k++;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int N, L, H;
struct node
{
    int id, virtue, talent;
    node(int _id, int _virtue, int _talent)
    {
        id = _id;
        virtue = _virtue;
        talent = _talent;
    }
};
vector<node> sage, nobleman, foolman, smallman;
bool cmp(const node &a, const node &b)
{
    if (a.virtue + a.talent != b.virtue + b.talent)
        return a.virtue + a.talent > b.virtue + b.talent;
    else if (a.virtue != b.virtue)
        return a.virtue > b.virtue;
    return a.id < b.id;
}
void printres(vector<node> res)
{
    for (auto &i : res)
        printf("%08d %d %d\n", i.id, i.virtue, i.talent);
}
int main()
{
    int id, virtue, talent;
    scanf("%d%d%d", &N, &L, &H);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d%d", &id, &virtue, &talent);
        if (virtue < L || talent < L)
            continue;
        if (virtue >= H && talent >= H)
            sage.push_back(node(id, virtue, talent));
        else if (virtue >= H && talent < H)
            nobleman.push_back(node(id, virtue, talent));
        else if (virtue < H && talent < H && virtue >= talent)
            foolman.push_back(node(id, virtue, talent));
        else
            smallman.push_back(node(id, virtue, talent));
    }
    sort(sage.begin(), sage.end(), cmp);
    sort(nobleman.begin(), nobleman.end(), cmp);
    sort(foolman.begin(), foolman.end(), cmp);
    sort(smallman.begin(), smallman.end(), cmp);
    printf("%d\n", sage.size() + nobleman.size() + foolman.size() + smallman.size());
    printres(sage);
    printres(nobleman);
    printres(foolman);
    printres(smallman);
    return 0;
}
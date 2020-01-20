#include <bits/stdc++.h>
using namespace std;

int n, temp1, tempX, tempY, minn = 1000000000, maxx = -1;
struct player
{
    int id, distance;
    player(int _id, int _distance) { id = _id; distance = _distance;}
};
vector<player> vec;
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &temp1, &tempX, &tempY);
        vec.push_back(player(temp1, tempX * tempX + tempY * tempY));
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i].distance < minn)
        {
            minn = vec[i].distance;
            tempX = i;
        }
        if(vec[i].distance > maxx)
        {
            maxx = vec[i].distance;
            tempY = i;
        }
    }
    printf("%04d %04d\n", vec[tempX].id, vec[tempY].id);
    return 0;
}
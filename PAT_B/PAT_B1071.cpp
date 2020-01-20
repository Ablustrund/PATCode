#include <bits/stdc++.h>
using namespace std;

int T, K, temp1, temp2, temp3, temp4;
struct Game
{
    int n1, b, t, n2;
    Game(int _n1, int _b, int _t, int _n2)
    {
        n1 = _n1;
        b = _b;
        t = _t;
        n2 = _n2;
    }
};
vector<Game> games;
int main()
{
    scanf("%d%d", &T, &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d%d%d%d", &temp1, &temp2, &temp3, &temp4);
        games.push_back(Game(temp1, temp2, temp3, temp4));
    }
    for (int i = 0; i < K; i++)
    {
        if(T < games[i].t) printf("Not enough tokens.  Total = %d.\n", T);
        else
        {
            if((games[i].n2 < games[i].n1 && !games[i].b) || (games[i].n2 > games[i].n1 && games[i].b))
            {
                T += games[i].t;
                printf("Win %d!  Total = %d.\n", games[i].t, T);
            }
            else
            {
                T -= games[i].t;
                printf("Lose %d.  Total = %d.\n", games[i].t, T);
            }
        }
        if(T == 0)
        {
            printf("Game Over.\n");
            break;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
/*
1. 在当前加油站i，假设距离加油站i的Cmax * Davg以内距离内，存在第一个加油站j，j的价格小于i的价格
那么在加油站只需要加油到可以行驶到j的地方
2. 如果不存在加油站j，那么就应该把油箱加满，然后行驶到下一个加油站k
3. 从加油站k重复1和2过程
*/
double Cmax, D, Davg, tempDis;
int N;
double tempPrice;
struct sta
{
    double price;
    double dis;
    sta(double _price = 0.0, double _dis = 0) { price = _price; dis = _dis;}
};
vector<sta> station;
bool cmp(const sta &a, const sta &b) { return a.dis < b.dis; }
int main()
{
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lf%lf", &tempPrice, &tempDis);
        station.push_back(sta(tempPrice, tempDis));
    }
    station.push_back(sta(0.0, D));//很重要
    sort(station.begin(), station.end(), cmp);
    if(station[0].dis != 0)
    {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    int i = 0;//当前的位置，在加油站i
    double tot = 0.0, Cnow = 0.0, canArrMaxDis = Cmax * Davg;//canArrMaxDis:满油状态能形式的最长距离
    while(i < N)
    {
        double arrMax = station[i].dis + canArrMaxDis;
        int k = i;
        bool flag = false;
        while(k <= N && station[k].dis <= arrMax)
        {
            if(station[k].price < station[i].price){flag = true;break;}
            k++;
        }
        if(flag == false) k = i;
        if(k == i)
        {
            if(arrMax < station[i+1].dis)
            {
                printf("The maximum travel distance = %.2f\n", arrMax);
                return 0;
            }
            else
            {
                tot += (Cmax - Cnow) * station[i].price;
                Cnow = Cmax;
                Cnow -= (station[i + 1].dis - station[i].dis) / Davg;
                i++;
            }
        }
        else
        {
            double temp = (station[k].dis - station[i].dis) / Davg;
            if(temp <= Cnow)
            {
                Cnow -= temp;
                i = k;
            }
            else
            {
                tot += station[i].price * (temp - Cnow);
                Cnow = 0.0;
                i = k;
            }
        }
    }
    printf("%.2f\n", tot);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, d;
double tempF, profit = 0;
double amounts[1010], prices[1010], pricePerTon[1010];
struct item
{
    double amount, prices, pricePerTon;
    item(double _amount, double _prices, double _pricePerTon)
    {
        amount = _amount;
        prices = _prices;
        pricePerTon = _pricePerTon;
    }
};
vector<item> items;
bool cmp(struct item &a, struct item &b) {return a.pricePerTon > b.pricePerTon;}
int main()
{
    scanf("%d%d", &n, &d);
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &tempF);
        items.push_back(item(tempF, 0, 0));
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &tempF);
        items[i].prices = tempF;
        items[i].pricePerTon = tempF / items[i].amount;
    }
    sort(items.begin(), items.end(), cmp);
    for (int i = 0; i < items.size(); i++)
    {
        if(d <= items[i].amount)
        {
            profit += items[i].pricePerTon * d;
            break;
        }
        else
        {
            profit += items[i].prices;
            d -= items[i].amount;
        }
    }
    printf("%.2lf\n", profit);
    return 0;
}
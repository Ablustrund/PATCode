#include <bits/stdc++.h>
using namespace std;
string tempId, tag;
int dayBill[25] = {0}, n, Mon, Day, Hour, Minute, tempTag;
bool firstPrint;
struct node
{
    int day, hour, minute, tag; //on-line: tag = 1; off-line: tag = 0;
    node(int _day = 0, int _hour = 0, int _minute = 0, int _tag = 0) {day = _day; hour = _hour; minute = _minute; tag = _tag;}
};
map<string, vector<node>> bills;
bool cmp(const node &a, const node &b)
{
    if(a.day != b.day) return a.day < b.day;
    else if(a.hour != b.hour) return a.hour < b.hour;
    return a.minute < b.minute;
}
double calFromZero(int day, int hour, int minute)
{
    double res = day * 60 * dayBill[24];
    for(int i = 0; i < hour; i++) res += 60 * dayBill[i];
    res += minute * dayBill[hour];
    return res;
}
int main()
{
    for (int i = 0; i < 24; i++) {scanf("%d", &dayBill[i]); dayBill[24] += dayBill[i];}//这里挺好的，在scanf的时候就将sum求出来了
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> tempId;
        scanf("%d:%d:%d:%d", &Mon, &Day, &Hour, &Minute);
        cin >> tag;
        tempTag = (tag == "on-line") ? 1 : 0;
        bills[tempId].push_back(node(Day, Hour, Minute, tempTag));
    }
    for (auto i = bills.begin(); i != bills.end(); i++)
    {
        sort(i->second.begin(), i->second.end(), cmp);
        double tot = 0;
        firstPrint = false;
        for (int j = 0; j < i->second.size(); j++)//这里不要用size()-1 !!
        {
            if(j == i->second.size()-1) break;
            if(i->second[j].tag == 1 && i->second[j+1].tag == 0)
            {
                double tempTol = 0;
                if(!firstPrint) printf("%s %02d\n%02d:%02d:%02d %02d:%02d:%02d %d", i->first.c_str(), Mon, i->second[j].day, i->second[j].hour, i->second[j].minute, i->second[j + 1].day, i->second[j + 1].hour, i->second[j + 1].minute, 24*60*(i->second[j+1].day-i->second[j].day) + 60*(i->second[j+1].hour-i->second[j].hour) + i->second[j+1].minute-i->second[j].minute);
                else printf("%02d:%02d:%02d %02d:%02d:%02d %d", i->second[j].day, i->second[j].hour, i->second[j].minute, i->second[j + 1].day, i->second[j + 1].hour, i->second[j + 1].minute, 24*60*(i->second[j+1].day-i->second[j].day) + 60*(i->second[j+1].hour-i->second[j].hour) + i->second[j+1].minute-i->second[j].minute);
                firstPrint = true;
                tempTol = calFromZero(i->second[j + 1].day, i->second[j + 1].hour, i->second[j + 1].minute) - calFromZero(i->second[j].day, i->second[j].hour, i->second[j].minute);
                tempTol *= 0.01;
                printf(" $%.2f\n", tempTol);
                tot += tempTol;
            }
        }
        if(firstPrint) printf("Total amount: $%.2f\n", tot);
    }
        return 0;
}
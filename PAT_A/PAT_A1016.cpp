#include <bits/stdc++.h>
using namespace std;
string tempId, tag;
int dayBill[24], n, Mon, Day, Hour, Minute, tempTag;
bool flaggg = false;
int countsprint = 0;
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
int main()
{
    for (int i = 0; i < 24; i++) scanf("%d", &dayBill[i]);
    int allDayBill = 0;
    for (int i = 0; i < 24; i++) allDayBill += dayBill[i];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> tempId;
        scanf("%d:%d:%d:%d", &Mon, &Day, &Hour, &Minute);
        cin >> tag;
        if(tag == "on-line") tempTag = 1;
        else tempTag = 0;
        bills[tempId].push_back(node(Day, Hour, Minute, tempTag));
    }
    for (auto i = bills.begin(); i != bills.end(); i++)
    {
        sort(i->second.begin(), i->second.end(), cmp);
        double tot = 0;
        flaggg = false;
        countsprint = 0;
        for (int j = 0; j < i->second.size(); j++)
        {
            if(j == i->second.size()-1) break;
            if(i->second[j].tag == 1 && i->second[j+1].tag == 0)
            {
                flaggg = true;
                double tempTol = 0;
                if(countsprint == 0) printf("%s %02d\n%02d:%02d:%02d %02d:%02d:%02d %d", i->first.c_str(), Mon, i->second[j].day, i->second[j].hour, i->second[j].minute, i->second[j + 1].day, i->second[j + 1].hour, i->second[j + 1].minute, 24*60*(i->second[j+1].day-i->second[j].day) + 60*(i->second[j+1].hour-i->second[j].hour) + i->second[j+1].minute-i->second[j].minute);
                else printf("%02d:%02d:%02d %02d:%02d:%02d %d", i->second[j].day, i->second[j].hour, i->second[j].minute, i->second[j + 1].day, i->second[j + 1].hour, i->second[j + 1].minute, 24*60*(i->second[j+1].day-i->second[j].day) + 60*(i->second[j+1].hour-i->second[j].hour) + i->second[j+1].minute-i->second[j].minute);
                countsprint++;
                tempTol += (i->second[j + 1].day - i->second[j].day) * allDayBill * 60;
                if(i->second[j].hour > i->second[j+1].hour)
                {
                    for (int k = i->second[j].hour; k >= i->second[j + 1].hour; k--)
                    {
                        if(k == i->second[j].hour) tempTol-=i->second[j].minute * dayBill[k];
                        else if(k == i->second[j+1].hour) tempTol-=(60 - i->second[j+1].minute) * dayBill[k];
                        else tempTol -= 60 * dayBill[k];
                    }
                }
                else if(i->second[j].hour == i->second[j+1].hour) tempTol+=(i->second[j+1].minute - i->second[j].minute) * dayBill[i->second[j].hour];
                else
                {
                    for (int k = i->second[j].hour; k <= i->second[j+1].hour; k++)
                    {
                        if(k == i->second[j].hour) tempTol+=(60 - i->second[j].minute) * dayBill[k];
                        else if(k == i->second[j+1].hour) tempTol+=i->second[j+1].minute * dayBill[k];
                        else tempTol += 60 * dayBill[k];
                    }
                }
                tempTol *= 0.01;
                printf(" $%.2f\n", tempTol);
                tot += tempTol;
            }
        }
        if(flaggg) printf("Total amount: $%.2f\n", tot);
    }
        return 0;
}
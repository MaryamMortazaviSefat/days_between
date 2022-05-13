#include <iostream>
#include <cstdlib>
using namespace std;


class Date {
public:
    Date(int d, int m, int y);
    void set_date(int d, int m, int y);
    void print_date();
    void inc_one_day();
    bool equals(Date d);
    int compare(Date);
    int days_between(Date d1,Date D2);
    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }
private:
    int day;
    int month;
    int year;
};

Date::Date(int d, int m, int y)
{
    set_date(d, m, y);
}

bool is_leap_year(int year)
{
    int r = year % 33;
    return r==1 || r==5 || r==9 || r==13 || r==17 || r==22 || r==26 || r==30;
}

int days_of_month(int m, int y)
{
    if (m < 7)
        return 31;
    else if (m < 12)
        return 30;
    else if (m == 12)
        return is_leap_year(y) ? 30 : 29;
    else
        abort();
}

void Date::set_date(int d, int m, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > days_of_month(m, y))
        abort();

    day = d;
    month = m;
    year = y;
}

void Date::inc_one_day()
{
    day++;
    if (day > days_of_month(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::print_date()
{
    cout << day << '/' << month << '/' << year << endl;
}

bool Date::equals(Date d) {
    return day == d.day &&
           month == d.month &&
           year == d.year;
}

int Date::compare(Date d2)
{
    if(year>d2.year)
    {cout<<"+";
    return 1;}
    else if(year==d2.year)
    {
        if(month>d2.month)
        {
        return 1;}
        else if(month==d2.month)
        {
            if(day>d2.day)
            {cout<<"+"; return 1;}
            else if(day==d2.day)
            {return 0;}
            else
            {return -1;}
        }
        else
        {return -1;}
    }
    else
    {return -1;}
}

int days_between(Date d1, Date d2) {
    if(d1.compare(d2)==1){
        Date temp(1,1,1);
        temp=d1;
        d1=d2;
        d2=temp;
    }

    int count = 1;
    while (!d1.equals(d2)) {
        d1.inc_one_day();
        count++;
    }
    return count;
}

int main()
{
    Date bd(10, 12, 1391);
    Date today(31, 6, 1352);
    cout << days_between(bd, today) << endl;
}

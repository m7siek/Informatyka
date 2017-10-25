//
//  calend_class.cpp
//  Calendar
//
//  Created by Michał Bernacki on 11.10.2017.
//  Copyright © 2017 Michał Bernacki. All rights reserved.
//

#include "calend_class.hpp"
#include <iostream>

using std::cout;
using std::ostream;
using std::endl;


Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day =d;
}
Date::Date(const Date & d1)
{
    year = d1.year;
    month = d1.month;
    day = d1.day;
}
Date Date::operator+(int n) const
{
    Date result;
    result.year += n/365;
    int local_d = n%365;
    
    while (local_d >= 28)
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (local_d >= 31) {
                local_d -= 31;
                if (month < 12) {
                    result.month++;
                }else
                    result.year++;
            }else
                continue;
        }
        else if(month == 2)
        {
            if (local_d >= 28) {
                local_d -= 28;
                result.month++;
            }else
                continue;
        }else
        {
            if (local_d >=30) {
                local_d -= 30;
                result.month++;
            }else
                continue;
        }
    }
    result.day += local_d;
    return result;
}
Date Date::operator-(int n) const
{
    Date result;
    result.year -= n/365;
    int local_d = n%365;
    
    while (local_d >= 28)
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (local_d >= 31) {
                local_d -= 31;
                if (month > 1) {
                    result.month--;
                }else
                    result.year--;
            }else
                continue;
        }
        else if(month == 2)
        {
            if (local_d >= 28) {
                local_d -= 28;
                result.month--;
            }else
                continue;
        }else
        {
            if (local_d >=30) {
                local_d -= 30;
                result.month--;
            }else
                continue;
        }
    }
    result.day -= local_d;
    return result;
}
Date Date::operator+=(int n)
{
    return *this = *this +n;
    
}
Date Date::operator-=(int n)
{
    return *this = *this -n;
}
int Date::convert()
{
    int days_count;
    int days_in_months;
    switch (this->month) {
        case 1:
            days_in_months = 0;
            break;
        case 2:
            days_in_months = 31;
            break;
        case 3:
            days_in_months = 59;
            break;
        case 4:
            days_in_months = 90;
            break;
        case 5:
            days_in_months = 120;
            break;
        case 6:
            days_in_months = 151;
            break;
        case 7:
            days_in_months = 181;
            break;
        case 8:
            days_in_months = 212;
            break;
        case 9:
            days_in_months = 243;
            break;
        case 10:
            days_in_months = 273;
            break;
        case 11:
            days_in_months = 304;
            break;
        case 12:
            days_in_months = 334;
            break;
    }
    days_count = this->year*365+days_in_months+this->day;
    return days_count;
}
int Date::operator-(Date & d)
{
    int d1 = d.convert();
    int d2 = this->convert();
    int result = d2-d1;
    return result;
}
bool Date::operator==(const Date & d) const
{
    if (d.year == year) {
        if (d.month == month) {
            if (d.day == day) {
                return true;
            }else
                return false;
        }else
            return false;
    }else
        return false;
}
bool Date::operator!=(const Date & d) const
{
    if (d == *this) {
        return false;
    }else
        return true;
}
ostream & operator<<(ostream & os, const Date & d)
{
    os << d.year <<"-"<<d.month<<"-"<<d.day<<endl;
    return os;
}

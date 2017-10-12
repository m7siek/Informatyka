//
//  calend_class.cpp
//  Calendar
//
//  Created by Michał Bernacki on 11.10.2017.
//  Copyright © 2017 Michał Bernacki. All rights reserved.
//

#include "calend_class.hpp"
#include <iostream>

using namespace std;


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
Date Date::operator-(const Date & d) const
{
    
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

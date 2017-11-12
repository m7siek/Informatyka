//
//  Date.cpp
//  Calendar2.0
//
//  Created by Michał Bernacki on 25.10.2017.
//  Copyright © 2017 Michał Bernacki. All rights reserved.
//

#include "Date.hpp"
#include <iomanip>
#include <sstream>

using std::ostream;
using std::cout;
using std::endl;


int Date::StartingYear = 1970;

Date::Date(int y, int m, int d)
{
    numberOfDaysFromTheVeryStart = ConvertToNumberOfDays(y, m, d);
}
Date Date::operator+(int n)
{
    numberOfDaysFromTheVeryStart = numberOfDaysFromTheVeryStart + n;
    return *this;
}
Date Date::operator-(int n)
{
    numberOfDaysFromTheVeryStart = numberOfDaysFromTheVeryStart - n;
    return *this;
}
int Date::operator-(const Date & d) const
{
    int result = numberOfDaysFromTheVeryStart - d.numberOfDaysFromTheVeryStart;
    return result;
}
ostream & operator<<(ostream & os, const Date & d)
{
    int year, day, days_left;
    int month = 1;
    if (d.numberOfDaysFromTheVeryStart > 0) {
        year = d.numberOfDaysFromTheVeryStart/365;
        days_left = d.numberOfDaysFromTheVeryStart%365;
        while (days_left >= 28) {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                if (days_left >=31) {
                    days_left -= 31;
                    month++;
                }else
                    break;
            }
            else if(month == 2){
                if (days_left >= 28) {
                    days_left -= 28;
                    month++;
                }else
                    break;
            }
            else{
                if (days_left >= 30) {
                    days_left -= 30;
                    month++;
                }else
                    break;
            }
        }
        day = days_left;
        os<<1970+year<<"-"<<std::setfill('0')<<std::setw(2)<<month<<"-"<<std::setfill('0')<<std::setw(2)<<day;
    }else
        cout<<"Data sprzed początku epoki"<<endl;
    return os;
}
std::string Date::View() const
{
    int year, day, days_left;
    int month = 1;
    if (numberOfDaysFromTheVeryStart > 0) {
        year = numberOfDaysFromTheVeryStart/365;
        days_left = numberOfDaysFromTheVeryStart%365;
        while (days_left >= 28) {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                if (days_left >=31) {
                    days_left -= 31;
                    month++;
                }else
                    break;
            }
            else if(month == 2){
                if (days_left >= 28) {
                    days_left -= 28;
                    month++;
                }else
                    break;
            }
            else{
                if (days_left >= 30) {
                    days_left -= 30;
                    month++;
                }else
                    break;
            }
        }
        day = days_left;
        std::stringstream buffer;
        buffer<<std::setfill('0')<<std::setw(2)<<day<<"."<<std::setfill('0')<<std::setw(2)<<month<<"."<<1970+year;
        return buffer.str();
    }else
        return "Data sprzed początu epoki";
}
int Date::ConvertToNumberOfDays(int year, int month, int day)
{
    int monthCount = 0;
    for (int i = 0; i < month - 1; i++)
        monthCount += monthDays[i];
    
    return (year-StartingYear) * 365 + monthCount + day;
}

//
//  Date.cpp
//  Calendar2.0
//
//  Created by Michał Bernacki on 25.10.2017.
//  Copyright © 2017 Michał Bernacki. All rights reserved.
//

#include "Date.hpp"

using std::ostream;
using std::cout;
using std::endl;


int Date::starting_year = 1970;

//To jest konstruktor nad którym jeszcze pracuję, bo to ma być taki idiotoodporny, np jakby ktoś wpisał w polu miesiąc 13 albo w polu dzien 77...xD
//ale to troszkę więcej zabawy jest więc jak na razie zostawiam taki, który zakłada, że ma do czynienia z normalnymi ludźmi ;)


//Date::Date(int y, int m, int d)
//{
//    int year = y;
//    int month;
//    int day;
//    if (m < 13)
//        month = m;
//    else
//        throw std::invalid_argument( "received negative value" );
//    if (d < 31)
//        day =d;
//    else
//        throw std::invalid_argument( "received negative value" );
//}


Date::Date(int y, int m, int d)
{
    number_of_days_from_the_very_start = convert_to_number_of_days(y, m, d);
}
Date Date::operator+(int n)
{
    number_of_days_from_the_very_start = number_of_days_from_the_very_start + n;
    return *this;
}
Date Date::operator-(int n)
{
    number_of_days_from_the_very_start = number_of_days_from_the_very_start - n;
    return *this;
}
int Date::operator-(const Date & d) const
{
    int result = number_of_days_from_the_very_start - d.number_of_days_from_the_very_start;
    return result;
}
ostream & operator<<(ostream & os, const Date & d)
{
    int year, day, days_left;
    int month = 1;
    if (d.number_of_days_from_the_very_start > 0) {
        year = d.number_of_days_from_the_very_start/365;
        days_left = d.number_of_days_from_the_very_start%365;
        os <<1970+year;
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
        os<<"-";
        if (month < 10) {
            os<<"0"<<month;
        }else
            os<<month;
        os<<"-";
        if (day < 10) {
            os<<"0"<<day;
        }else
            os<<day;
    }else
        cout<<"Data sprzed początku epoki"<<endl;
    return os;
}
int Date::convert_to_number_of_days(int year, int month, int day)
{
    int days_count;
    int days_in_months;
    switch (month) {
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
    days_count = (year-starting_year)*365+days_in_months+day;
    return days_count;
}

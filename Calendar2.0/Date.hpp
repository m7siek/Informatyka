//
//  Date.hpp
//  Calendar2.0
//
//  Created by Michał Bernacki on 25.10.2017.
//  Copyright © 2017 Michał Bernacki. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include <iostream>

class Date
{
private:
    int number_of_days_from_the_very_start;
    int convert_to_number_of_days(int, int, int);
    static int starting_year;
public:
    Date(int y = 1970, int m = 1, int d = 1);
    Date operator+(int n);
    Date & operator+=(int n) {return (*this = *this+n);}
    Date & operator-=(int n) {return (*this = *this-n);}
    Date operator-(int n);
    int operator-(const Date & d) const;
    bool operator==(const Date & d) const {return (number_of_days_from_the_very_start == d.number_of_days_from_the_very_start);}
    bool operator!=(const Date & d) const {return (number_of_days_from_the_very_start != d.number_of_days_from_the_very_start);}
    friend Date operator+(int n, Date & c) {return c+n;}
    friend std::ostream & operator<<(std::ostream & os, const Date & d);    
};

#endif /* Date_hpp */

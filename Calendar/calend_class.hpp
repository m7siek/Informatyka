//
//  calend_class.hpp
//  Calendar
//
//  Created by Michał Bernacki on 11.10.2017.
//  Copyright © 2017 Michał Bernacki. All rights reserved.
//

#ifndef calend_class_hpp
#define calend_class_hpp

#include <iostream>

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(int y = 1970, int m = 1, int d = 1);
    Date(const Date &);
    Date operator+(int n) const;
    Date operator-(int n) const;
    Date operator-(const Date & d) const;
    bool operator==(const Date & d) const;
    bool operator!=(const Date & d) const;
    friend Date operator+(int n, Date & c) {return c+n;}
    friend std::ostream & operator<<(std::ostream & os, const Date & d);

};

#endif /* calend_class_hpp */

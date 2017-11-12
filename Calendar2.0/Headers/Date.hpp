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
#include <array>

class Date
{
private:
    int numberOfDaysFromTheVeryStart;
    int ConvertToNumberOfDays(int, int, int);
    static int StartingYear;
    std::array<int,12> monthDays = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
public:
    Date(int y = 1970, int m = 1, int d = 1);
    Date operator+(int n);
    Date & operator+=(int n) {return (*this = *this+n);}
    Date & operator-=(int n) {return (*this = *this-n);}
    Date operator-(int n);
    int operator-(const Date & d) const;
    bool operator==(const Date & d) const {return (numberOfDaysFromTheVeryStart == d.numberOfDaysFromTheVeryStart);}
    bool operator!=(const Date & d) const {return (numberOfDaysFromTheVeryStart != d.numberOfDaysFromTheVeryStart);}
    friend Date operator+(int n, Date & c) {return c+n;}
    friend std::ostream & operator<<(std::ostream & os, const Date & d);
    std::string View() const;
};

#endif /* DateFormater_hpp */

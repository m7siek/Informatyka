//
//  DateFormater.hpp
//  Calendar2.0
//
//  Created by Michał Bernacki on 12.11.2017.
//  Copyright © 2017 Michał Bernacki. All rights reserved.
//

#ifndef DateFormater_hpp
#define DateFormater_hpp

#include <iostream>
#include "Date.hpp"

class DateFormater
{
public:
    virtual std::string format(const Date& d) const = 0;

};
class ComputerDateFormater : public DateFormater
{
    virtual std::string format(const Date& d) const;
};
class GermanDateFormater : public DateFormater
{
    virtual std::string format(const Date& d) const;

};
#endif /* Date_hpp */



//
//  DateFormater.cpp
//  Calendar2.0
//
//  Created by Michał Bernacki on 12.11.2017.
//  Copyright © 2017 Michał Bernacki. All rights reserved.
//

#include "DateFormater.hpp"
#include <iostream>
#include <sstream>

std::string ComputerDateFormater::format(const Date& d) const
{
    std::stringstream buffer;
    buffer << d;
    return buffer.str();
}

std::string GermanDateFormater::format(const Date& d) const
{
    return d.View();
}


//
//  main.cpp
//  Calendar
//
//  Created by Michał Bernacki on 11.10.2017.
//  Copyright © 2017 Michał Bernacki. All rights reserved.
//

#include <iostream>
#include "calend_class.hpp"

using namespace std;

int main()
{
    Date d1;
    Date d2(2004, 11, 27);
    Date d3(1988, 8, 5);
    cout <<"d1\n"<< d1<<endl;
    cout <<"d2\n"<< d2<<endl;
    cout <<"d3\n"<< d3<<endl;
    cout <<"d1 + 560\n"<< d1 + 560<<endl;
    return 0;
}

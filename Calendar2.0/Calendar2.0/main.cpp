//
//  main.cpp
//  Calendar2.0
//
//  Created by Michał Bernacki on 25.10.2017.
//  Copyright © 2017 Michał Bernacki. All rights reserved.
//

#include <iostream>
#include "Date.hpp"

using std::cout;
using std::endl;

int main()
{
    Date d1(1930, 8, 9);
    cout<<"d1\n"<<d1<<endl;
    Date d2;
    cout<<"d2\n"<<d2<<endl;
    Date d3(2007, 8, 10);
    cout<<"d3\n"<<d3<<endl;
    Date d4(2017, 12, 30);
    cout<<"d4\n"<<d4<<endl;
    cout<<"d4-d3\n"<<(d4-d3)<<endl;
    cout<<"d2 + 1050\n"<<(d2+1050)<<endl;
    cout<<"d2 - 1050\n"<<(d2-1050)<<endl;
    if (d4 == d2) {
        cout <<"Tak"<<endl;
    }else
        cout <<"Nie"<<endl;
    if (d4 != d2) {
        cout <<"Tak"<<endl;
    }else
        cout <<"Nie"<<endl;
    cout<<"d4 += 5007\n"<<(d4+=5007)<<endl;
    cout<<"d4 -= 5007\n"<<(d4-=5007)<<endl;

    return 0;
}

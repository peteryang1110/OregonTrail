#ifndef CHECKNUM_H
#define CHECKNUM_H
#include <iostream>
using namespace std;

class checknum {
    private: 
        bool digit;
        string out;
    public:
        checknum();
        string checkdigit(string);
};

#endif
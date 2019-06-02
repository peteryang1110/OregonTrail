#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class date {
    private:
        bool check;
        int year;
        int month;
        int day;
    public:
        date();
        date(int, int);
        void setday(int);
        int getyear();
        int getmonth();
        int getday();
        bool getcheck();
};

#endif
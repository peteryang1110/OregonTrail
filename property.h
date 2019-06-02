#ifndef PROPERTY_H
#define PROPERTY_H
#include <iostream>
using namespace std;

class property {
    private:
        int oxen;
        int food;
        int bullet;
        int supply[4];
        string wagon[3];
        double cash;
    public:
        property();
        int getoxen();
        void setoxen(int);
        int getfood();
        void setfood(int);
        int getbullet();
        void setbullet(int);
        int getsupply(int);
        void setsupply(int, int);
        string getwagon(int);
        double getcash();
        void setcash(double);
};

#endif
#ifndef TURN_H
#define TURN_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "property.h"
#include "bad.h"
#include "date.h"
#include "name.h"
#include "milestone.h"
#include "game.h"
#include "hunt.h"
#include "checknum.h"
using namespace std;

class turn {
    private:
        property p;
        bad b;
        date d;
        name n[5];
        milestone m;
        game g;
        hunt h;
        checknum c;
        string lose[7];
        bool why[7];
        int fort;
        int river;
        int count;
        int And;
        bool encountered[5];
        string choice;
        int next;
        bool arrived;
        bool check;
        double bill;
        string answer;
        string indate;
        string inmonth;
        int numuser;
    public:
        turn();
        bool milestones();
        void start();
        void username();
        void store();
        void depart();
        void status();
        void menu();
        void misfortune();
        void attack();
        string getchoice();
        bool getcheck();
        bool arrive();
        void getwhy(int num);
        void ending();
};

#endif
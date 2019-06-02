#ifndef HUNT_H
#define HUNT_H
#include <iostream>
using namespace std;

class hunt {
    private:
        string animal[5];
        bool encounter[5];
    public:
        hunt();
        string getanimal(int);
        bool getencounter(int);
};

#endif
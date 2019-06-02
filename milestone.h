#ifndef MILESTONE_H
#define MILESTONE_H
#include <iostream>
#include <fstream>
using namespace std;

class milestone {
    private:
        int distance;
        string rivername[4];
        int rivermile[4];
        int riverfoot[4];
        string fortname[6];
        int fortmile[6];
        int end;
        bool state;
    public:
        milestone();
        void setdistance(int);
        int getdistance();
        int getnext();
        bool setriver();
        string getrivername(int);
        int getrivermile(int);
        int getriverfeet(int);
        bool setfort();
        string getfortname(int);
        int getfortmile(int);
        bool getstate();
};

#endif
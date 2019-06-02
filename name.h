#ifndef NAME_H
#define NAME_H
#include <iostream>
using namespace std;

class name {
    private:
        string user;
        bool condition;
    public:
        name();
        void setuser(string);
        string getuser();
        bool getcondition();
        void dead();
};

#endif
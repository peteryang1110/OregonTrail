#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;

class game {
    private:
        bool result;
        int num;
    public:
        game();
        void play();
        bool getresult();
};

#endif
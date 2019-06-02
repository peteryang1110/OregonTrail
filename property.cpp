#include "property.h"

property::property() { // initialize the properties.
    oxen = 0;
    food = 0;
    bullet = 0;
    for (int i = 0; i < 4; i++) {
        supply[i] = 0;
    }
    cash = 1200;
    wagon[0] = "wheels";
    wagon[1] = "axles";
    wagon[2] = "tongues";
}

int property::getoxen() { // return the amount of oxen.
    return oxen;
}

void property::setoxen(int num) { // set the amount of oxen.
    oxen += num;
}

int property::getfood() { // return the amount of food.
    return food;
}

void property::setfood(int num) { // set the amount of food.
    food += num;
}

int property::getbullet() { // return the amount of bullets.
    return bullet;
}

void property::setbullet(int num) { // set the amount of bullets.
    bullet += num;
}

int property::getsupply(int num) { // return the amount of different supplies.
    return supply[num];
}

void property::setsupply(int index, int num) { // set the amount of different supplies.
    supply[index] += num;
}

string property::getwagon(int num) { // return the name of different supplies.
    return wagon[num];
}

double property::getcash() { // return the amount of cash.
    return cash;
}

void property::setcash(double num) { // set the amount of cash.
    cash += num;
}

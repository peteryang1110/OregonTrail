#include "hunt.h"

hunt::hunt() { // the name of each animal.
    animal[0] = "rabbit";
    animal[1] = "fox";
    animal[2] = "deer";
    animal[3] = "bear";
    animal[4] = "moose";
    for (int i = 0; i < 5; i++) {
        encounter[i] = false;
    }
}

string hunt::getanimal(int num) { // return the aninal you encounter.
    return animal[num];
}

bool hunt::getencounter(int num) { // compute what you encounter in this turn. if you encounter the specific animal, make the "encounter[]" become true.
    int get;
    srand(time(0));
    
    get = rand() % 100 + 1;
    if (num == 0) {
        if (get <= 50 && get >= 1) {
            return true;
        }
    } else if (num == 1) {
        if (get <= 25 && get >= 1) {
            return true;
        }
    } else if (num == 2) {
        if (get <= 15 && get >= 1) {
            return true;
        }
    } else if (num == 3) {
        if (get <= 7 && get >= 1) {
            return true;
        }
    } else if (num == 4) {
        if (get <= 5 && get >= 1) {
            return true;
        }
    }
    return false;
}

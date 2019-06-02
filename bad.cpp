#include "bad.h"

bad::bad() {

}

int bad::getprob() { // if this function return a number which is not 0, it means the misfortune happens, and the number represents different misfortunes.
    int mis;
    srand(time(0));
    
    mis = rand() % 10 + 1;
    if (mis >= 1 && mis <= 4) {
        mis = rand() % 3 + 1;
        return mis;
    }
    return 0;
}

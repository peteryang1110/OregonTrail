#include "checknum.h"

checknum::checknum() {
    digit = false;
    out = "";
}

string checknum::checkdigit(string in) { // to check if the input is an integer. if it is not, make the user enter another number until the input is correct.
    out = in;
    while (digit == false) {
        digit = true;
        for (int i = 0; i < out.length(); i++) {
            if (!isdigit(out[i])) {
                digit = false;
            }
        }
        if (digit == false) {
            cout << endl << "Please enter a positive integer: ";
            cin >> out;
        }
    }
    digit = false;
    return out;
}

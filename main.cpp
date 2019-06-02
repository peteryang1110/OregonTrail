#include <iostream>
#include "turn.h"
using namespace std;

int main() {
    turn t;
    
    if (t.milestones() == false) { // read the file and input the milestones to the database.
        cout << "Please put the files of milestones in the folder." << endl;
        return 0;
    }
    t.start(); // print out the information of the game.
    t.username(); // input usernames.
    t.store(); // visit the store.
    t.depart(); // choose the day to depart.
    while (t.getcheck() == true && t.arrive() == false) { // if the condition is still fine, keep the game going.
        t.status(); // print out the status.
        t.menu(); // make the user choose what's going to doing in this turn.
        if (t.getchoice() != "4") { // whenever the choice is not "quit," run this part.
            t.misfortune(); // check if misfortune happens in this turn.
            if (t.getcheck() == true) { // if the condition is still fine, check if the raiders attack.
                t.attack(); // check if the raiders attack.
            }
        }
    }
    if (t.arrive() == true) { // print out the result.
        cout << endl << "You win!" << endl;
    } else if (t.getcheck() == false) {
        cout << endl << "You lose because:" << endl;
        for (int i = 0; i < 7; i++) {
            t.getwhy(i);
        }
    }
    cout << endl;
    t.ending(); // print out the final status, and input to the result.txt
}

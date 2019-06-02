#include "game.h"

game::game() {
    result = false;
}

void game::play() { // the function is for puzzle game. if the user wins, the function will print out the result, and the variable "result" will be true.
    string answer;
    srand(time(0));
    num = rand() % 10 + 1;
    bool check = false;
    
    result = false;
    cout << endl << "Please enter a number between 1 and 10 to win the puzzle game: ";
    cin >> answer;
    while (check == false) {
        check = true;
        for (int i = 0; i < answer.length(); i++) {
            if (!isdigit(answer[i])) {
                check = false;
            }
        }
        if (check == false) {
            cout << endl << "Please enter a number: ";
            cin >> answer;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (stoi(answer) == num) {
            break;
        } else {
            cout << "The number is wrong. Please try another time!" << endl;
            cout << "Please enter a number between 1 and 10 to win the puzzle game: ";
            cin >> answer;
            check = false;
            while (check == false) {
                check = true;
                for (int i = 0; i < answer.length(); i++) {
                    if (!isdigit(answer[i])) {
                        check = false;
                    }
                    if (check == false) {
                        cout << endl << "Please enter a number: ";
                        cin >> answer;
                    }
                }
                while (stoi(answer) > 10 || stoi(answer) < 1) {
                    cout << "The number is not between 1 and 10. Please enter a number again: ";
                    cin >> answer;
                    check = false;
                    while (check == false) {
                        check = true;
                        for (int i = 0; i < answer.length(); i++) {
                            if (!isdigit(answer[i])) {
                                check = false;
                            }
                            if (check == false) {
                                cout << endl << "Please enter a number: ";
                                cin >> answer;
                            }
                        }
                    }
                }
            }
        }
    }
    if (stoi(answer) == num) {
        cout << endl << "You won the game!" << endl;
        result = true;
    }
    if (result == false) {
        cout << endl << "You lost the game." << endl;
    }
}

bool game::getresult() { // return the result.
    return result;
}

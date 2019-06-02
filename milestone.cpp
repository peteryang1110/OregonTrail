#include "milestone.h"

milestone::milestone() { // start at 0 mile. end is 2040 miles.
    distance = 0;
    end = 2040;
}

void milestone::setdistance(int num) { // increase the distance depending on the input number.
    distance += num;
}

int milestone::getdistance() { // return the distance.
    return distance;
}

int milestone::getnext() { // return the distance to next milestone.
    int fort, river;
    
    for (int i = 0; i < 4; i++) {
        if (distance - rivermile[i] >= 0) {
            continue;
        }
        river = rivermile[i] - distance;
        break;
    }
    for (int i = 0; i < 6; i++) {
        if (distance - fortmile[i] >= 0) {
            continue;
        }
        fort = fortmile[i] - distance;
        break;
    }
    if (fort <= 0 || river <= 0) {
        return end - distance;
    } else if (fort <= river) {
        state = false;
        return fort;
    } else {
        state = true;
        return river;
    }
}

bool milestone::setriver() { // input the names, depth, and distances to database.
    string out = "", miles = "", feet = "";
    bool check = true;
    ifstream read;
    read.open("river-milestones.txt");
    
    if (read.fail()) {
        return false;
    }
    for (int j = 0; j < 4; j++) {
        getline(read, rivername[j]);
        getline(read, out);
        for (int i = 0; i < out.length(); i++) {
            if (out[i] == ' ') {
                check = false;
                continue;
            }
            if (isdigit(out[i]) && check == true) {
                miles += out[i];
            }
            if (isdigit(out[i]) && check == false) {
                feet += out[i];
            }
        }
        rivermile[j] = stoi(miles);
        riverfoot[j] = stoi(feet);
        miles = "";
        feet = "";
        check = true;
    }
    return true;
}

string milestone::getrivername(int num) { // return the name of the river.
    return rivername[num];
}

int milestone::getrivermile(int num) { // return the distance of the river.
    return rivermile[num];
}

int milestone::getriverfeet(int num) { // return the depth of the river.
    return riverfoot[num];
}

bool milestone::setfort() { // input the distances and names to the database.
    string out = "", miles = "";
    ifstream read;
    read.open("fort-milestones.txt");
    
    if (read.fail()) {
        return false;
    }
    for (int j = 0; j < 6; j++) {
        getline(read, fortname[j]);
        getline(read, out);
        for (int i = 0; i < out.length(); i++) {
            if (isdigit(out[i])) {
                miles += out[i];
            }
        }
        fortmile[j] = stoi(miles);
        miles = "";
    }
    return true;
}

string milestone::getfortname(int num) { // return the name of the fort.
    return fortname[num];
}

int milestone::getfortmile(int num) { // return the distance of the fort.
    return fortmile[num];
}

bool milestone::getstate() { // return next milestone is a fort or a river.
    return state;
}

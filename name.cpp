#include "name.h"

name::name() { // initialize the database.
    user = "";
    condition = true;
}

void name::setuser(string in) { // input the username.
    user = in;
}

string name::getuser() { // return the name of the user.
    return user;
}

bool name::getcondition() { // return if the user is dead or alive.
    return condition;
}

void name::dead() { // if the user is dead, make the condition be false.
    condition = false;
}

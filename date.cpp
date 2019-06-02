#include "date.h"

date::date() {
    year = 1847;
    month = 3;
    day = 28;
    check = true;
}

date::date(int inmonth, int inday) {
    year = 1847;
    month = inmonth;
    day = inday;
    check = true;
}

void date::setday(int num) { // according to the month and the input "day," the month should add 1 whenever the date is over the limit.
    day += num;
    switch (month) {
        case 3: {
            if (day > 31) {
                month += 1;
                day -= 31;
            }
            break;
        }
        case 4: {
            if (day > 30) {
                month += 1;
                day -= 30;
            }
            break;
        }
        case 5: {
            if (day > 31) {
                month += 1;
                day -= 31;
            }
            break;
        }
        case 6: {
            if (day > 30) {
                month += 1;
                day -= 30;
            }
            break;
        }
        case 7: {
            if (day > 31) {
                month += 1;
                day -= 31;
            }
            break;
        }
        case 8: {
            if (day > 31) {
                month += 1;
                day -= 31;
            }
            break;
        }
        case 9: {
            if (day > 30) {
                month += 1;
                day -= 30;
            }
            break;
        }
        case 10: {
            if (day > 31) {
                month += 1;
                day -= 31;
            }
            break;
        }
        case 11: {
            if (day > 30) {
                month += 1;
                day -= 30;
                check = false;
            }
            break;
        }
        default: {
            break;
        }
    }
}

int date::getyear() { // return the year.
    return year;
}

int date::getmonth() { // return the month.
    return month;
}

int date::getday() { // return the day.
    return day;
}

bool date::getcheck() { // return if the date is before 11/30 or not.
    return check;
}

#include "turn.h"

turn::turn() {
    lose[0] = "The party runs out of food.";
    lose[1] = "The party has lost all the oxen.";
    lose[2] = "The party has a broken wagon and has no wagon parts left.";
    lose[3] = "The leader of the party dies.";
    lose[4] = "The party runs out of cash to cross the river.";
    lose[5] = "You quit the game.";
    lose[6] = "You run out of time.";
    for (int i = 0; i < 7; i++) {
        why[i] = false;
    }
    check = true;
    numuser = 5;
    arrived = false;
    river = 0;
    fort = 0;
}

bool turn::milestones() {
    if (m.setriver() == false) {
        return false;
    }
    if (m.setfort() == false) {
        return false;
    }
    return true;
}

void turn::start() {
    cout << endl << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM" << endl;
    cout << "INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847. YOUR FAMILY OF" << endl;
    cout << "FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5-6 MONTHS --- IF YOU" << endl;
    cout << "MAKE IT ALIVE." << endl;
}

void turn::username() {
    int i = 0;
    string in;
    
    cout << endl << "What is the first name of the wagon leader?" << endl;
    cin >> in;
    n[i].setuser(in);
    for (i = 1; i < 5; i++) {
        cout << "What are the first names of the four other members in your party?" << endl;
        cin >> in;
        n[i].setuser(in);
    }
}

void turn::store() {
    string schoice = "", oxen = "0", food = "0", bullet = "0", wheel = "0", axle = "0", tongue = "0", aid = "0";
    bill = 0;
    
    cout << endl <<"YOU HAD SAVED $1200 TO SPEND FOR THE TRIP, AND YOU'VE JUST PAID $200" << endl;
    cout << "FOR A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE" << endl;
    cout << "FOLLOWING ITEMS:" << endl;
    cout << "- OXEN. YOU CAN SPEND $100-$200 ON YOUR TEAM. THE MORE YOU SPEND," << endl;
    cout << "THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS" << endl;
    cout << "- FOOD. THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK" << endl;
    cout << "- AMMUNITION - YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND" << endl;
    cout << "BANDITS, AND FOR HUNTING FOOD" << endl;
    cout << "- MISCELLANEOUS SUPPLIES. THIS INCLUDES MEDICINE AND OTHER THINGS" << endl;
    cout << "YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS" << endl;
    cout << "YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN" << endl;
    cout << "SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN" << endl;
    cout << "LOW. HOWEVER, ITEMS COST MORE AT THE FORTS. YOU CAN ALSO GO HUNTING" << endl;
    cout << "ALONG THE WAY TO GET MORE FOOD." << endl;
    cout << endl;
    while (schoice != "5" || oxen == "0" || wheel == "0" || axle == "0" || tongue == "0" || food == "0") {
        cout << "1. Oxen\n2. Food\n3. Bullets\n4. Miscellaneous Supplies\n5. Quit" << endl;
        cout << "Which item would you like to buy?" << endl;
        cin >> schoice;
        if (!(schoice == "1" || schoice == "2" || schoice == "3" || schoice == "4" || schoice == "5")) {
            cout << endl << "Invalid choice. Please enter another choice." << endl;
        }
        if (schoice == "1") {
            cout << endl << "You must spend between $100 and $200 dollars on oxen, inclusive." << endl;
            cout << "There are 2 oxen in a yoke and the price of each yoke is $40." << endl;
            cout << "How many yoke do you want?" << endl;
            while (cin >> oxen) {
                oxen = c.checkdigit(oxen);
                if (oxen >= "3" && oxen <= "5") {
                    bill = stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25;
                    if (bill > p.getcash()) {
                        cout << endl << "The price exceeds the total cash you has in hand." << endl;
                        cout << "Please enter another number." << endl;
                        bill -= stoi(oxen) * 40;
                    } else {
                        cout << endl << "The current bill is $" << bill << endl;
                        break;
                    }
                } else {
                    cout << endl << "Invalid amount. Please enter another number." << endl;
                }
            }
        }
        if (schoice == "2") {
            cout << endl << "I recommend you should purchase at least 200 lbs. of food per person, at 50 cents per pound." << endl;
            cout << "How many pounds of food do you want?" << endl;
            cin >> food;
            food = c.checkdigit(food);
            while (stoi(food) > 1000) {
                cout << endl << "Since the wagon cannot hold more than 1000 pounds of food. Please enter another number." << endl;
                cin >> food;
                food = c.checkdigit(food);
            }
            bill = stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25;
            while (bill > p.getcash()) {
                cout << endl << "The price exceeds the total cash you has in hand." << endl;
                cout << "Please enter another number." << endl;
                bill -= stoi(food) * 0.5;
                cin >> food;
                food = c.checkdigit(food);
                bill = stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25;
            }
            cout << endl << "The current bill is $" << bill << endl;
        }
        if (schoice == "3") {
            cout << endl << "A box of 20 bullets costs $2." << endl;
            cout << "How many boxes of bullets do you want?" << endl;
            cin >> bullet;
            bullet = c.checkdigit(bullet);
            bill = stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25;
            while (bill > p.getcash()) {
                cout << endl << "The price exceeds the total cash you has in hand." << endl;
                cout << "Please enter another number." << endl;
                bill -= stoi(bullet) * 2;
                cin >> bullet;
                bullet = c.checkdigit(bullet);
                bill = stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25;
            }
            cout << endl << "The current bill is $" << bill << endl;
        }
        if (schoice == "4") {
            cout << endl << "A wagon part (wheels, axles, tongues) costs $20." << endl;
            cout << "How many wagon wheels do you want?" << endl;
            cin >> wheel;
            wheel = c.checkdigit(wheel);
            cout << "How many wagon axles do you want?" << endl;
            cin >> axle;
            axle = c.checkdigit(axle);
            cout << "How many wagon tongues do you want?" << endl;
            cin >> tongue;
            tongue = c.checkdigit(tongue);
            cout << "A medical aid kit costs $25." << endl;
            cout << "How many medical aid kits do you want?" << endl;
            cin >> aid;
            aid = c.checkdigit(aid);
            bill = stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25;
            while (bill > p.getcash()) {
                cout << endl << "The price exceeds the total cash you has in hand." << endl;
                cout << "Please enter another number." << endl;
                bill -= stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25;
                cout << endl << "A wagon part (wheels, axles, tongues) costs $20." << endl;
                cout << "How many wagon wheels do you want?" << endl;
                cin >> wheel;
                wheel = c.checkdigit(wheel);
                cout << "How many wagon axles do you want?" << endl;
                cin >> axle;
                axle = c.checkdigit(axle);
                cout << "How many wagon tongues do you want?" << endl;
                cin >> tongue;
                tongue = c.checkdigit(tongue);
                cout << "A medical aid kit costs $25." << endl;
                cout << "How many medical aid kits do you want?" << endl;
                cin >> aid;
                aid = c.checkdigit(aid);
                bill = stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25;
            }
            cout << endl << "The current bill is $" << bill << endl;
        }
        if (schoice == "5") {
            if (oxen == "0" || wheel == "0" || axle == "0" || tongue == "0" || food == "0") {
                cout << endl;
                if (oxen == "0") {
                    cout << "You haven't buy oxen yet. Please purchase some before you leave the store." << endl;
                }
                if (food == "0") {
                    cout << "You haven't buy food yet. Please purchase some before you leave the store." << endl;
                }
                if (wheel == "0" || axle == "0" || tongue == "0") {
                    cout << "You haven't buy wagon parts yet. Please purchase some before you leave the store." << endl;
                }
            }
        }
    }
    p.setoxen(stoi(oxen));
    p.setfood(stoi(food));
    p.setbullet(stoi(bullet) * 20);
    p.setsupply(0, stoi(wheel));
    p.setsupply(1, stoi(axle));
    p.setsupply(2, stoi(tongue));
    p.setsupply(3, stoi(aid));
    p.setcash(-1 * bill);
}

void turn::depart() {
    cout << endl<< "You have the choice to start on the default start date of 03/28/1847 or" << endl;
    cout << "to choose a different departure date between 03/01/1847 and 05/01/1847." << endl;
    cout << "Do you want to start on the default start date? (Y/N)" << endl;
    cin >> answer;
    while (!(answer == "Y" || answer == "N" || answer == "y" || answer == "n")) {
        cout << endl << "Invalid answer! Please enter Y or N." << endl;
        cin >> answer;
    }
    if (answer == "Y" || answer == "y") {
        d = date();
    }
    if (answer == "N" || answer == "n") {
        cout << endl << "Please enter the month you want to depart." << endl;
        cin >> inmonth;
        inmonth = c.checkdigit(inmonth);
        cout << "Please enter the date you want to depart." << endl;
        cin >> indate;
        indate = c.checkdigit(indate);
        while (inmonth == "5" && indate > "1") {
            cout << endl << "The input is invalid. Please enter another date." << endl;
            cout << "Please enter the month you want to depart." << endl;
            cin >> inmonth;
            inmonth = c.checkdigit(inmonth);
            cout << "Please enter the date you want to depart." << endl;
            cin >> indate;
            indate = c.checkdigit(indate);
        } 
        while (inmonth == "3" && !(indate >= "1" && indate <= "31")) {
            cout << endl << "The input is invalid. Please enter another date." << endl;
            cout << "Please enter the month you want to depart." << endl;
            cin >> inmonth;
            inmonth = c.checkdigit(inmonth);
            cout << "Please enter the date you want to depart." << endl;
            cin >> indate;
            indate = c.checkdigit(indate);
        } 
        while (inmonth == "4" && !(indate >= "1" && indate <= "30")) {
            cout << endl << "The input is invalid. Please enter another date." << endl;
            cout << "Please enter the month you want to depart." << endl;
            cin >> inmonth;
            inmonth = c.checkdigit(inmonth);
            cout << "Please enter the date you want to depart." << endl;
            cin >> indate;
            indate = c.checkdigit(indate);
        } 
        while (inmonth < "3" || inmonth > "5" || indate > "31" || indate < "1") {
            cout << endl << "The input is invalid. Please enter another date." << endl;
            cout << "Please enter the month you want to depart." << endl;
            cin >> inmonth;
            inmonth = c.checkdigit(inmonth);
            cout << "Please enter the date you want to depart." << endl;
            cin >> indate;
            indate = c.checkdigit(indate);
        }
        d = date(stoi(inmonth), stoi(indate));
    }
}

void turn::status() {
    cout << endl << "Current date: " << d.getmonth() << "-" << d.getday() << "-" << d.getyear() << endl;
    cout << "Miles traveled: " << m.getdistance() << " mile(s)" << endl;
    cout << "Distance until the next milestone: " << m.getnext() << " mile(s)" << endl;
    cout << "Food available: " << p.getfood() << " lb" << endl;
    cout << "Number of Bullets available: " << p.getbullet() << " bullet(s)" << endl;
    cout << "Cash available: $" << fixed << setprecision(2) << p.getcash() << endl;
}

void turn::menu() {
    int day, distance;
    string schoice = "", oxen = "0", food = "0", bullet = "0", wheel = "0", axle = "0", tongue = "0", aid = "0";
    bool buy;
    double price;
    srand(time(0));
    
    cout << endl << "Do you want to (1) Rest, (2) Continue, (3) Hunt, or (4) Quit?" << endl;
    cin >> choice;
    while (!(choice == "1" || choice == "2" || choice == "3" || choice == "4")) {
        cout << endl << "Invalid input. Please enter another choice." << endl;
        cin >> choice;
    }
    if (choice == "1") {
        day = (rand() % 3) + 1;
        d.setday(day);
        p.setfood(-numuser * day * 3);
    }
    if (choice == "3") {
        d.setday(1);
        count = 0;
        And = 0;
        for (int i = 0; i < 5; i++) {
            encountered[i] = h.getencounter(i);
            if (encountered[i] == true) {
                count += 1;
            }
        }
        if (count != 0) {
            cout << endl << "You got lucky! You encountered";
            for (int i = 0; i < 5; i++) {
                if (count == 1 && encountered[i] == true) {
                    cout << " a " << h.getanimal(i) << "!";
                } else if (count == 2 && encountered[i] == true) {
                    cout << " " << h.getanimal(i) << " and ";
                    for (int j = i + 1; j < 5; j++) {
                        if (encountered[j] == true) {
                            cout << h.getanimal(j) << "!";
                        }
                    }
                    break;
                } else if (encountered[i] == true && And == count - 1) {
                    cout << " and " << h.getanimal(i) << "!";
                } else if (encountered[i] == true && And != count) {
                    cout << " " << h.getanimal(i) << ",";
                    And++;
                }
            }
            cout << " Do you want to hunt? (Y/N)" << endl;
            cin >> answer;
            while (!(answer == "Y" || answer == "N" || answer == "y" || answer == "n")) {
                cout << endl << "Invalid answer! Please enter Y or N." << endl;
                cin >> answer;
            }
            if (answer == "Y" || answer == "y") {
                if (p.getbullet() < 10) {
                    cout << endl << "The hunt is unsuccessful because you have less than 10 bullets left." << endl;
                } else {
                    g.play();
                    if (g.getresult() == true) {
                        for (int i = 0; i < 5; i++) {
                            switch (encountered[i]) {
                                case true: {
                                    switch (i) {
                                        case 0: {
                                            p.setfood(2);
                                            p.setbullet(-10);
                                            break;
                                        }
                                        case 1: {
                                            p.setfood(5);
                                            p.setbullet(-8);
                                            break;
                                        }
                                        case 2: {
                                            p.setfood(rand() % 26 + 30);
                                            p.setbullet(-5);
                                            break;
                                        }
                                        case 3: {
                                            p.setfood(rand() % 251 + 100);
                                            p.setbullet(-10);
                                            break;
                                        }
                                        case 4: {
                                            p.setfood(rand() % 301 + 300);
                                            p.setbullet(-12);
                                            break;
                                        }
                                        default: {
                                            break;
                                        }
                                    }
                                }
                                default: {
                                    break;
                                }
                            }
                        }
                    } else {
                        for (int i = 0; i < 5; i++) {
                            switch (encountered[i]) {
                                case true: {
                                    switch (i) {
                                        case 0: {
                                            p.setbullet(-10);
                                            break;
                                        }
                                        case 1: {
                                            p.setbullet(-8);
                                            break;
                                        }
                                        case 2: {
                                            p.setbullet(-5);
                                            break;
                                        }
                                        case 3: {
                                            p.setbullet(-10);
                                            break;
                                        }
                                        case 4: {
                                            p.setbullet(-12);
                                            break;
                                        }
                                        default: {
                                            break;
                                        }
                                    }
                                }
                                default: {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            cout << endl << "You did not encounter any animal in this turn. Let's try next time." << endl;
        }
        cout << "How well do you want to eat? (1) Poorly, (2) Moderately, or (3) Well" << endl;
        cin >> choice;
        while (!(choice == "1" || choice == "2" || choice == "3")) {
            cout << endl << "Invalid input. Please enter another choice." << endl;
            cin >> choice;
        }
        if (choice == "1") {
            p.setfood(- numuser * 2);
        } else if (choice == "2") {
            p.setfood(- numuser * 3);
        } else {
            p.setfood(- numuser * 5);
        }
        if (p.getfood() > 1000) {
            p.setfood(- p.getfood() + 1000);
            cout << endl << "Since the wagon cannot hold more than 1000 pounds of food. The rest of food is left behind." << endl;
        }
    }
    if (choice == "2") {
        day = 14;
        distance = (rand() % 71) + 70;
        if (m.getdistance() + distance >= m.getrivermile(river) && m.getstate() == true) {
            cout << endl;
            cout << "You were prepared to travel " << distance << " miles but you arrived at the " << m.getrivername(river) << endl;
            cout << "What do you want to do? (1) Rest or (2) Cross the river." << endl;
            cin >> choice;
            while (!(choice == "1" || choice == "2")) {
                cout << endl << "Invalid input. Please enter another choice." << endl;
                cin >> choice;
            }
            while (choice == "1") {
                d.setday(1);
                p.setfood(-numuser * 3);
                cout << endl << "You have rested for a day. Do you want to (1) Rest again or (2) Cross the river?" << endl;
                cin >> choice;
                while (!(choice == "1" || choice == "2")) {
                    cout << endl << "Invalid input. Please enter another choice." << endl;
                    cin >> choice;
                }
            }
            if (choice == "2") {
                if (m.getriverfeet(river) > 3) {
                    if (p.getcash() < numuser * 10) {
                        cout << endl << "You cannot cross the river because you don't have enough cash." << endl;
                        why[4] = true;
                    } else {
                        cout << endl << "Since the river is deeper than 3 feet, you need to purchase a ferry to cross the river." << endl;
                        cout << "The ferry costs $10 per person." << endl;
                        p.setcash(-numuser * 10);
                    }
                }
                m.setdistance(-m.getdistance() + m.getrivermile(river));
                river++;
            }
        } else if (m.getdistance() + distance >= m.getfortmile(fort) && m.getstate() == false) {
            cout << endl;
            cout << "You were prepared to travel " << distance << " miles but you arrived at the " << m.getfortname(fort) << endl;
            cout << "What do you want to do? (1) Rest, (2) Visit the store, or (3) Continue the journey." << endl;
            cin >> choice;
            while (!(choice == "1" || choice == "2" || choice == "3")) {
                cout << endl << "Invalid input. Please enter another choice." << endl;
                cin >> choice;
            }
            while (choice == "1" || choice == "2" || choice == "3") {
                if (choice == "1") {
                    while (choice == "1") {
                        d.setday(1);
                        p.setfood(-numuser * 3);
                        cout << endl << "You have rested for a day. Do you want to (1) Rest again, (2) Visit the store, or (3) Continue the journey?" << endl;
                        cin >> choice;
                        while (!(choice == "1" || choice == "2" || choice == "3")) {
                            cout << endl << "Invalid input. Please enter another choice." << endl;
                            cin >> choice;
                        }
                    }
                }
                if (choice == "2") {
                    price = (fort + 1)* 0.25 + 1;
                    cout << endl;
                    schoice = "";
                    oxen = "0";
                    food = "0"; 
                    bullet = "0";
                    wheel = "0";
                    axle = "0";
                    tongue = "0";
                    aid = "0";
                    bill = 0;
                    while (schoice != "5") {
                        cout << "1. Oxen\n2. Food\n3. Bullets\n4. Miscellaneous Supplies\n5. Quit" << endl;
                        cout << "Which item would you like to buy?" << endl;
                        cin >> schoice;
                        if (!(schoice == "1" || schoice == "2" || schoice == "3" || schoice == "4" || schoice == "5")) {
                            cout << endl << "Invalid choice. Please enter another choice." << endl;
                        }
                        if (schoice == "1") {
                            cout << endl << "There are 2 oxen in a yoke and the price of each yoke is $" << fixed << setprecision(0) << 40 * price << "." << endl;
                            cout << "How many yoke do you want?" << endl;
                            while (cin >> oxen) {
                                oxen = c.checkdigit(oxen);
                                bill = price * (stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25);
                                if (bill > p.getcash()) {
                                    cout << endl << "The price exceeds the total cash you has in hand." << endl;
                                    cout << "Please enter another number." << endl;
                                    bill -= stoi(oxen) * 40 * price;
                                } else {
                                    cout << endl << "The current bill is $" << fixed << setprecision(2) << bill << endl;
                                    break;
                                }
                            }
                        }
                        if (schoice == "2") {
                            cout << endl << "The food is " << setprecision(0) << 50 * price << " cents per pound." << endl;
                            cout << "How many pounds of food do you want?" << endl;
                            cin >> food;
                            food = c.checkdigit(food);
                            while (p.getfood() + stoi(food) > 1000) {
                                cout << endl << "Since the wagon cannot hold more than 1000 pounds of food. Please enter another number." << endl;
                                cin >> food;
                                food = c.checkdigit(food);
                            }
                            bill = price * (stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25);
                            while (bill > p.getcash()) {
                                cout << endl << "The price exceeds the total cash you has in hand." << endl;
                                cout << "Please enter another number." << endl;
                                bill -= stoi(food) * 0.5 * price;
                                cin >> food;
                                food = c.checkdigit(food);
                                bill = price * (stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25);
                            }
                            cout << endl << "The current bill is $" << fixed << setprecision(2) << bill << endl;
                        }
                        if (schoice == "3") {
                            cout << endl << "A box of 20 bullets costs $" << 2 * price << "." << endl;
                            cout << "How many boxes of bullets do you want?" << endl;
                            cin >> bullet;
                            bullet = c.checkdigit(bullet);
                            bill = price * (stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25);
                            while (bill > p.getcash()) {
                                cout << endl << "The price exceeds the total cash you has in hand." << endl;
                                cout << "Please enter another number." << endl;
                                bill -= stoi(bullet) * 2 * price;
                                cin >> bullet;
                                bullet = c.checkdigit(bullet);
                                bill = price * (stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25);
                            }
                            cout << endl << "The current bill is $" << fixed << setprecision(2) << bill << endl;
                        }
                        if (schoice == "4") {
                            cout << endl << "A wagon part (wheels, axles, tongues) costs $" << setprecision(0) << 20 * price << "." << endl;
                            cout << "How many wagon wheels do you want?" << endl;
                            cin >> wheel;
                            wheel = c.checkdigit(wheel);
                            cout << "How many wagon axles do you want?" << endl;
                            cin >> axle;
                            axle = c.checkdigit(axle);
                            cout << "How many wagon tongues do you want?" << endl;
                            cin >> tongue;
                            tongue = c.checkdigit(tongue);
                            cout << "A medical aid kit costs $" << setprecision(2) << 25 * price << "." << endl;
                            cout << "How many medical aid kits do you want?" << endl;
                            cin >> aid;
                            aid = c.checkdigit(aid);
                            bill = price * (stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25);
                            while (bill > p.getcash()) {
                                cout << endl << "The price exceeds the total cash you has in hand." << endl;
                                cout << "Please enter another number." << endl;
                                bill -= price * (stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25);
                                cout << endl << "A wagon part (wheels, axles, tongues) costs $20." << endl;
                                cout << "How many wagon wheels do you want?" << endl;
                                cin >> wheel;
                                wheel = c.checkdigit(wheel);
                                cout << "How many wagon axles do you want?" << endl;
                                cin >> axle;
                                axle = c.checkdigit(axle);
                                cout << "How many wagon tongues do you want?" << endl;
                                cin >> tongue;
                                tongue = c.checkdigit(tongue);
                                cout << "A medical aid kit costs $" << 25 * price << "." << endl;
                                cout << "How many medical aid kits do you want?" << endl;
                                cin >> aid;
                                aid = c.checkdigit(aid);
                                bill = price * (stoi(oxen) * 40 + stoi(food) * 0.5 + stoi(bullet) * 2 + stoi(wheel) * 20 + stoi(axle) * 20 + stoi(tongue) * 20 + stoi(aid) * 25);
                            }
                            cout << endl << "The current bill is $" << fixed << setprecision(2) << bill << endl;
                        }
                    }
                    p.setoxen(stoi(oxen));
                    p.setfood(stoi(food));
                    p.setbullet(stoi(bullet) * 20);
                    p.setsupply(0, stoi(wheel));
                    p.setsupply(1, stoi(axle));
                    p.setsupply(2, stoi(tongue));
                    p.setsupply(3, stoi(aid));
                    p.setcash(-1 * bill);
                    buy = true;
                    cout << endl << "You have visited the store. Do you want to (1) Rest, (2) Visit the store again or (3) Continue the journey?" << endl;
                    cin >> choice;
                    while (!(choice == "1" || choice == "2" || choice == "3")) {
                        cout << endl << "Invalid input. Please enter another choice." << endl;
                        cin >> choice;
                    }
                }
                if (choice == "3" && buy == false) {
                    m.setdistance(distance);
                    fort++;
                    break;
                }
                if (choice == "3" && buy == true) {
                    m.setdistance(-m.getdistance() + m.getfortmile(fort));
                    fort++;
                    break;
                }
            }
        } else {
            m.setdistance(distance);    
        }
        d.setday(day);
        p.setfood(-numuser * day * 3);
    }
}

void turn::misfortune() {
    int unlucky, person, disease, dead, c, wagon;
    srand(time(0));
    string diseases[6] = {"typhoid", "cholera", "diarrhea", "measles", "dysentery", "fever"};
    
    unlucky = b.getprob();
    if (unlucky == 1) {
        person = rand() % 5;
        while (n[person].getcondition() == false) {
            person = rand() % 5;
        }
        disease = rand() % 6;
        cout << endl << "Oh no! " << n[person].getuser() << " has the " << diseases[disease] << "!" << endl;
        if (p.getsupply(3) > 0) {
            p.setsupply(3, -1);
            dead = rand() % 2;
            if (dead == 0) {
                cout << "You used a medical kit, and " << n[person].getuser() << " survives!" << endl;
            } else {
                cout << "You used a medical kit, but " << n[person].getuser() << " is dead." << endl;
                n[person].dead();
                numuser -= 1;
            }
        } else {
            cout << "You have no medical kit now. Do you want to (1) Rest or (2) Press on?" << endl;
            cin >> c;
            while (c > 2 || c < 1) {
                cout << endl << "Invalid input. Please enter another choice." << endl;
                cin >> c;
            }
            if (c == 1) {
                d.setday(3);
                p.setfood(-numuser * 3 *3);
                dead = rand() % 10 + 1;
                if (dead >= 1 && dead <= 3) {
                    cout << endl << "You chose to rest, but " << n[person].getuser() << " still died." << endl;
                    n[person].dead();
                    numuser -= 1;
                } else {
                    cout << endl << "You chose to rest, and " << n[person].getuser() << " survives!" << endl;
                }
            } else {
                dead = rand() % 10 + 1;
                if (dead >= 1 && dead <= 7) {
                    cout << endl << "You chose to press on, and " << n[person].getuser() << " is dead." << endl;
                    n[person].dead();
                    numuser -= 1;
                } else {
                    cout << endl << "You chose to press on, and " << n[person].getuser() << " survives!" << endl;
                }
            }
        }
    } else if (unlucky == 2) {
        p.setoxen(-1);
        if (p.getoxen() > 1) {
            cout << endl << "Oh no! One of the oxen has died! You have " << p.getoxen() << " oxen left." << endl;
        } else if (p.getoxen() == 1) {
            cout << endl << "Oh no! One of the oxen has died! You have an ox left." << endl;
        } else {
            cout << endl << "Oh no! The last ox has died! You have no ox left." << endl;
        }
    } else if (unlucky == 3) {
        wagon = rand() % 3;
        cout << endl << "Oh no! One of your " << p.getwagon(wagon) << " is broken!" << endl;
        p.setsupply(wagon, -1);
    }
}

void turn::attack() {
    int chance, attack, wagon;
    srand(time(0));
    
    chance = (((pow(m.getdistance() / 100 - 4, 2) + 72) / (pow(m.getdistance() / 100 - 4, 2) + 12)) - 1) / 10 * 100;
    attack = rand() % 101 + 1;
    if (attack >= 1 && attack <= chance) {
        cout << endl << "Riders ahead! They look hostile!" << endl;
        cout << "What do you want to do? (1) Run, (2) Attack, or (3) Surrender." << endl;
        cin >> choice;
        while (!(choice == "1" || choice == "2" || choice == "3")) {
            cout << endl << "Invalid input. Please enter another choice." << endl;
            cin >> choice;
        }
        if (choice == "1") {
            cout << endl << "You chose to run. Therefore, 1 ox, 10 pounds of food, and 1 wagon part are left behind." << endl;
            wagon = rand() % 3;
            p.setoxen(-1);
            p.setfood(-10);
            p.setsupply(wagon, -1);
        }
        if (choice == "2") {
            cout << endl << "You chose to attack." << endl;
            g.play();
            if (g.getresult() == true) {
                p.setfood(50);
                p.setbullet(50);
                if (p.getfood() > 1000) {
                    p.setfood(- p.getfood() + 1000);
                    cout << endl << "Since the wagon cannot hold more than 1000 pounds of food. The rest of food is left behind." << endl;
                }
            } else {
                p.setcash(-p.getcash() / 4);
                p.setbullet(-50);
            }
        }
        if (choice == "3") {
            cout << endl << "You chose to surrender." << endl;
            p.setcash(-p.getcash() / 4);
        }
    }
}

string turn::getchoice() {
    return choice;
}

bool turn::getcheck() {
    if (choice == "4") {
        check = false;
        why[5] = true;
    }
    if (d.getcheck() == false) {
        check = false;
        why[6] = true;
    }
    for (int i = 0; i < 3; i++) {
        if (p.getsupply(i) == 0) {
            check = false;
            why[2] = true; 
        }
    }
    if (n[0].getcondition() == false) {
        check = false;
        why[3] = true;
    }
    if (p.getoxen() == 0) {
        check = false;
        why[1] = true;
    }
    if (p.getfood() <= 0) {
        check = false;
        why[0] = true;
    }
    
    return check;
}

bool turn::arrive() {
    if (m.getdistance() >= 2040) {
        return true;
    }
    return false;
}

void turn::getwhy(int num) {
    if (why[num] == true) {
        cout << lose[num] << endl;
    }
}

void turn::ending() {
    if (p.getfood() < 0) {
        p.setfood(-p.getfood());
    }
    if (m.getdistance() > 2040) {
        m.setdistance(-m.getdistance() + 2040);
    }
    if (p.getcash() < 0) {
        p.setcash(-p.getcash());
    }
    cout << "The name the leader: " << n[0].getuser() << endl;
    cout << "Miles traveled: " << m.getdistance() << " miles" << endl;
    cout << "Food remaining: " << p.getfood() << " pounds" << endl;
    cout << "Cash remaining: $" << p.getcash() << endl;
    
    ofstream out;
    out.open("result.txt");
    out << "The name the leader: " << n[0].getuser() << endl;
    out << "Miles traveled: " << m.getdistance() << " miles" << endl;
    out << "Food remaining: " << p.getfood() << " pounds" << endl;
    out << "Cash remaining: $" << fixed << setprecision(2) << p.getcash() << endl;
}
//
// Created by tk on 7/6/26.
//

#include <iostream>
#include <cmath>

#include "../includes/moon.h"
#include "../includes/positionStar.h"

using namespace std;

double moonAge(double julianDay) {
    constexpr double synodicMonth = 29.530588853;
    constexpr double knownNewMoon = 2451550.1;

    double age = fmod(julianDay - knownNewMoon, synodicMonth);

    if (age < 0) age += synodicMonth;

    return age;
}

void calcMoonPhase() {
    double julianDay = calculateJDUTC();

    double age = moonAge(julianDay);

    string baseResponse = "Hoje a lua está ";

    if(age < 1.84566)
        cout << baseResponse + "Nova\n";

    else if(age < 5.53699)
        cout << baseResponse + "Crescente\n";

    else if(age < 9.22831)
        cout << baseResponse + "Quarto Crescente\n";

    else if(age < 12.91963)
        cout << baseResponse + "Gibosa Crescente\n";

    else if(age < 16.61096)
        cout << baseResponse + "Cheia\n";

    else if(age < 20.30228)
        cout << baseResponse + "Gibosa Minguante\n";

    else if(age < 23.99361)
        cout << baseResponse + "Quarto Minguante\n";

    else if(age < 27.68493)
        cout << baseResponse + "Minguante\n";

    else
        cout << baseResponse + "Nova\n";
}
//
// Created by tk on 7/5/26.
//

#include <iostream>
#include "../includes/positionStar.h"
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

vector<Star> stars;

void populateStarsVector() {
    if (stars.size() != 0) {
        return;
    }
    stars.push_back({"Betelgeuse (Órion)", 5, 55, 10, 7, 24, 25});
    stars.push_back({"Sirius (Cão Maior)", 6, 45, 8, -16, 42, 58});
    stars.push_back({"Alpha Centauri A (Centauri)", 14, 39, 36, -60, 50, 02});
    stars.push_back({"Alpha Centauri B (Centauri)", 14, 39, 35, -60, 50, 15});
    stars.push_back({"Canopus (Carina)", 6, 23, 57, -52, 41, 44});
    stars.push_back({"Mintaka (Órion)", 5, 32, 0, -0, 17, 56});
    stars.push_back({"Alnilam (Órion)", 5, 36, 12, -1, 12, 6});
    stars.push_back({"Alnitak (Órion)", 5, 40, 45, -1, 56, 33});
    stars.push_back({"Rígel (Órion)", 5, 14, 32, -8, 12, 5});
    stars.push_back({"Alpha Crucis (Cruzeiro do Sul)", 12, 26, 35, -63, 5, 56});
    stars.push_back({"Beta Crucis (Cruzeiro do Sul)", 12, 47, 43, -59, 41, 19});
    stars.push_back({"Gamma Crucis (Cruzeiro do Sul)", 12, 31, 10, -57, 6, 47});
}

void calculatePositionStar(int indexStar) {
    Star star = stars[indexStar];
    double raDegrees = rightAscensionToDegrees(star.raHours, star.raMinutes, star.raSeconds);

    double julianDay = calculateJDUTC();

    double tsg = calculateTSG(julianDay);
    double tsl = calculateTSL(tsg, -48.85);
    double hourAngle = calculateHourAngle(tsl, raDegrees);
    double height = calculateHeight(-26.3, star.decDegrees, star.decMinutes, star.decSeconds, hourAngle);
    double azimuth = calculateAzimuth(-26.3, star.decDegrees, star.decMinutes, star.decSeconds, hourAngle);

    if (height < 0) {
        cout << star.name + " não está vísivel no momento\n";
    }
    else {
        if (azimuth < 90) {
            cout << star.name + " está à norte, com Azimute em " + to_string(azimuth) + "º e Altitude " + to_string(height) + "º acima do horizonte.\n";
        }
        else if (azimuth < 180) {
            cout << star.name + " está à leste, com Azimute em " + to_string(azimuth) + "º e Altitude " + to_string(height) + "º acima do horizonte.\n";
        }
        else if (azimuth < 270) {
            cout << star.name + " está à sul, com Azimute em " + to_string(azimuth) + "º e Altitude " + to_string(height) + "º acima do horizonte.\n";
        }
        else {
            cout << star.name + " está à oeste, com Azimute em " + to_string(azimuth) + "º e Altitude " + to_string(height) + "º acima do horizonte.\n";
        }
    }
}
//
// Created by tk on 7/4/26.
//

#ifndef ASTRO_SYSTEM_POSITIONSTAR_H
#define ASTRO_SYSTEM_POSITIONSTAR_H
#include <vector>
#include <string>

using namespace std;

double rightAscensionToDegrees(int hours, int minutes, int seconds); // Cálculo da Ascensão Reta (AR)
double calculateJDUTC(int year, int month, int day, int hour, int minute, int second); // Cálculo do número do dia Juliano
double calculateTSG(double julianDay); // Cálculo do Tempo Sideral de Greenwich (TSG)
double calculateTSL(double tsg, double longitude); // Cálculo do Tempo Sideral Local (TSL)
double calculateHourAngle(double tsl, double ar);
double calculateHeight(double latitude, int degreeDeclination, int minutesDeclination, int secondDeclination, double hourAngle);
double calculateAzimuth(double latitude, int degreeDeclination, int minutesDeclination, int secondDeclination, double hourAngle);
void populateStarsVector();
void calculatePositionStar(int indexStar);
struct Star {
    string name;
    int raHours;
    int raMinutes;
    int raSeconds;
    int decDegrees;
    int decMinutes;
    int decSeconds;
};
extern vector<Star> stars;
// Se sen(AH) > 0 -> A = 360º - A

#endif //ASTRO_SYSTEM_POSITIONSTAR_H

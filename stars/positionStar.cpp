//
// Created by tk on 7/4/26.
//
#include <iostream>
#include <cmath>
#include <numbers>
#include <algorithm>
#include "../includes/positionStar.h"

using namespace std;
using namespace numbers;

constexpr double DEG_TO_RAD = pi / 180;
constexpr double RAD_TO_DEG = 180.0 / pi;

double rightAscensionToDegrees(int hours, int minutes, int seconds) {
    return (hours + minutes/60.0 + seconds/3600.0) * 15.0;
}

double calculateJDUTC(int year, int month, int day, int hour, int minute, int second) {
    double dayFraction = (hour + minute / 60.0 + second / 3600.0) / 24.0;

    if (month <= 2) {
        year--;
        month += 12;
    }

    int A = year / 100;
    int B = 2 - A + A / 4;

    return floor(365.25 * (year + 4716))
         + floor(30.6001 * (month + 1))
         + day
         + dayFraction
         + B
         - 1524.5;
}

double calculateTSG(double julianDay) {
    const double t = (julianDay - 2451545.0) / 36525.0;
    double tsg = 280.46061837 + 360.98564736629 * (julianDay - 2451545) + 0.000387933*pow(t, 2) - pow(t, 3)/38710000;
    tsg = fmod(tsg,360.0);
    if (tsg < 0) tsg += 360.0;
    return tsg;
}

double calculateTSL(const double tsg, const double longitude) {
    double tsl = fmod(tsg + longitude,360);
    if (tsl < 0) tsl += 360.0;
    return tsl;
}

double calculateHourAngle(double tsl, double ar) {
    double hourAngle = tsl - ar;
    hourAngle = fmod(hourAngle,360.0);
    if (hourAngle < 0) hourAngle += 360.0;
    return hourAngle;
}

double calculateHeight(double latitude, int degreeDeclination, int minutesDeclination, int secondDeclination, double hourAngle) {
    double declination = abs(degreeDeclination) + minutesDeclination / 60.0 + secondDeclination / 3600.0;

    if (degreeDeclination < 0)
        declination = -declination;
    double declinationRad = declination * DEG_TO_RAD;
    double hourAngleRad = hourAngle * DEG_TO_RAD;
    double latitudeRad = latitude * DEG_TO_RAD;
    double senH = sin(declinationRad) * sin(latitudeRad) + cos(declinationRad) * cos(latitudeRad) * cos(hourAngleRad);
    senH = clamp(senH, -1.0, 1.0);
    double h = asin(senH) * RAD_TO_DEG;
    return h;
}

double calculateAzimuth(double latitude, int degreeDeclination, int minutesDeclination, int secondsDeclination, double hourAngle) {
    double declination = abs(degreeDeclination) + minutesDeclination / 60.0 + secondsDeclination / 3600.0;

    if (degreeDeclination < 0) declination = -declination;

    double latRad = latitude * DEG_TO_RAD;
    double decRad = declination * DEG_TO_RAD;
    double haRad  = hourAngle * DEG_TO_RAD;

    double y = -cos(decRad) * sin(haRad);

    double x = sin(decRad) * cos(latRad) - cos(decRad) * sin(latRad) * cos(haRad);

    double azimuth = atan2(y, x) * RAD_TO_DEG;

    if (azimuth < 0)
        azimuth += 360.0;

    return azimuth;
}

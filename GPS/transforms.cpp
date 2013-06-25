#include "transforms.h"
#include <cmath>

QString Transforms::toDegrees(long double x) {
    x = x / M_PI * 180.0;
    int deg = floor(x);
    x = (x - deg) * BASE;
    int min = floor(x);
    x = (x - min) * BASE;
    double sec = x;
    return QString::number(deg) + "deg " + QString::number(min) + "' " + QString::number(sec) + "''";
}

QString Transforms::toHours(long double x) {
    x = x / M_PI * 12;
    int hour = floor(x);
    x = (x - hour) * BASE;
    int min = floor(x);
    x = (x - min) * BASE;
    double sec = x;
    return QString::number(hour) + "h " + QString::number(min) + "m " + QString::number(sec) + "s";
}

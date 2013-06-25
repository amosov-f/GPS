#ifndef SATELLITE_H
#define SATELLITE_H

#include <string>

using namespace std;

struct Satellite {
    string name;

    long double t_oe;
    long double dt_s;
    long double WN;
    long double e;
    long double A_sqrt;
    long double Omega0;
    long double i0;
    long double omega;
    long double M0;
    long double dn;
    long double velOmega;
    long double IDOT;
    long double c_uc;
    long double c_us;
    long double c_rc;
    long double c_rs;
    long double c_ic;
    long double c_is;
};

#endif // SATELLITE_H

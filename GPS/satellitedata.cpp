#include "satellitedata.h"
#include "fundamental.h"
#include "keplerequation.h"
#include "equationsystemsolver.h"
#include <cmath>
#include <iostream>

using namespace std;
using namespace Fundamental;

QVector3D SatelliteData::getSatelliteLocation() const {
    cout.precision(10);

    cout << name << endl << endl;

    //average motion
    long double n0 = sqrt(mu) / pow(A_sqrt, 3);
    cout << "n0 = " << n0 << endl;

    //time of the satellite signal radiation
    long double t_em = t_obs - P / c;
    cout << "t_em = " << t_em << endl << endl;

    //time of epoch start
    long double t = t_em - t_oe;
    cout << "t = " << t << endl << endl;

    //corrected average motion
    long double n = n0 + dn;
    cout << "n = " << n << endl << endl;

    //mean anomaly
    long double M = M0 + n * t;
    cout << "M = " << M << endl << endl;

    //eccentric anpmaly
    long double E = EquationSystemSolver::solve(new KeplerEquation(e, M), vector<long double>(1))[0];
    cout << "E = " << E << endl << endl;

    //true anomaly
    long double nu = 2.0 * atan(sqrt((1.0 + e) / (1.0 - e)) * tan(E / 2.0));
    if (nu - E > M_PI) {
        nu -= M_PI;
    }
    if (nu - E < - M_PI) {
        nu += M_PI;
    }
    cout << "nu = " << nu << endl << endl;

    //latitude argument
    long double phi = nu + omega;
    cout << "phi = " << phi << endl << endl;

    //modifications
    long double du = c_us * sin(2 * phi) + c_uc * cos(2 * phi);
    long double dr = c_rs * sin(2 * phi) + c_rc * cos(2 * phi);
    long double di = c_is * sin(2 * phi) + c_ic * cos(2 * phi);
    cout << "du = " << du << endl;
    cout << "dr = " << dr << endl;
    cout << "di = " << di << endl << endl;

    //corrects
    long double u = phi + du;
    long double r = pow(A_sqrt, 2) * (1 - e * cos(E)) + dr;
    long double i = i0 + di + IDOT * t;
    cout << "u = " << u << endl;
    cout << "r = " << r << endl;
    cout << "i = " << i << endl << endl;

    //orbital position
    long double x_orb = r * cos(u);
    long double y_orb = r * sin(u);
    cout << "x_orb = " << x_orb << endl;
    cout << "y_orb = " << y_orb << endl << endl;

    //corrected longitude of ascending node
    long double Omega = Omega0 + (velOmega - velOmega_e) * t - velOmega_e * t_oe;
    cout << "Omega = " << Omega << endl << endl;

    //result
    long double x = x_orb * cos(Omega) - y_orb * cos(i) * sin(Omega);
    long double y = x_orb * sin(Omega) + y_orb * cos(i) * cos(Omega);
    long double z = y_orb * sin(i);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

    return QVector3D(x, y, z);
}

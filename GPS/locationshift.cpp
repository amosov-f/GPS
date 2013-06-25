#include "locationshift.h"
#include "fundamental.h"
#include <cmath>

using namespace Fundamental;

LocationShift::LocationShift(const vector<pair<QVector3D, long double> >& data) {
    pos.resize(data.size());
    P.resize(data.size());

    for (size_t i = 0; i < data.size(); ++i) {
        pos[i] = data[i].first;
        P[i] = data[i].second;
    }
}

long double LocationShift::get(const vector<long double> &approx, size_t i) const {
    long double X = approx[0];
    long double Y = approx[1];
    long double Z = approx[2];
    long double dt = approx[3];

    return pow(pos[i].x() - X, 2) + pow(pos[i].y() - Y, 2) + pow(pos[i].z() - Z, 2) - pow(P[i] + c * dt, 2);
}

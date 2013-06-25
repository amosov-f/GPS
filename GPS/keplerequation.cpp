#include "keplerequation.h"
#include <cmath>

KeplerEquation::KeplerEquation(long double e, long double M) {
    this->e = e;
    this->M = M;
}

long double KeplerEquation::get(const vector<long double>& x, size_t) const {
    return x[0] - e * sin(x[0]) - M;
}

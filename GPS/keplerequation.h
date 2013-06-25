#ifndef KEPLEREQUATION_H
#define KEPLEREQUATION_H

#include "function.h"

class KeplerEquation : public Function {
public:
    KeplerEquation(long double e, long double M);

    long double get(const vector<long double> &x, size_t) const;

private:
    long double e, M;
};

#endif // KEPLEREQUATION_H

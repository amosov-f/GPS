#ifndef LOCATIONSHIFT_H
#define LOCATIONSHIFT_H

#include "function.h"
#include <QVector3D>

class LocationShift : public Function {
public:
    LocationShift(const vector<pair<QVector3D, long double> >& data);

    long double get(const vector<long double> &x, size_t i) const;
private:
    vector<QVector3D> pos;
    vector<long double> P;
};

#endif // LOCATIONSHIFT_H

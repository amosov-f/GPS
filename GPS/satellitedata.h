#ifndef SATELLITEDATA_H
#define SATELLITEDATA_H

#include "satellite.h"
#include <QVector3D>

using namespace std;

class SatelliteData : public Satellite {
public:
    long double P;
    long double t_obs;

    QVector3D getSatelliteLocation() const;
};

#endif // SATELLITEDATA_H

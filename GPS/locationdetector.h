#ifndef LOCATIONDETECTOR_H
#define LOCATIONDETECTOR_H

#include <vector>
#include "satellitedata.h"

using namespace std;

class LocationDetector {
public:
    static QPointF getLocation(const vector<SatelliteData>& data);

private:
    LocationDetector();
};

#endif // LOCATIONDETECTOR_H

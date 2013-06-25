#include "locationdetector.h"
#include "transforms.h"
#include <iostream>
#include <fstream>

using namespace Transforms;

int main() {
    ifstream fin("data.dat");

    vector<SatelliteData> satellites(4);
    for (size_t i = 0; i < satellites.size(); ++i) {
        string s;
        fin >> s >> satellites[i].name;
        fin >> s >> satellites[i].t_oe;
        fin >> s >> satellites[i].WN;
        fin >> s >> satellites[i].e;
        fin >> s >> satellites[i].A_sqrt;
        fin >> s >> satellites[i].Omega0;
        fin >> s >> satellites[i].i0;
        fin >> s >> satellites[i].omega;
        fin >> s >> satellites[i].M0;
        fin >> s >> satellites[i].dn;
        fin >> s >> satellites[i].velOmega;
        fin >> s >> satellites[i].IDOT;
        fin >> s >> satellites[i].c_uc;
        fin >> s >> satellites[i].c_us;
        fin >> s >> satellites[i].c_rc;
        fin >> s >> satellites[i].c_rs;
        fin >> s >> satellites[i].c_ic;
        fin >> s >> satellites[i].c_is;
        fin >> s >> satellites[i].P;
        fin >> s >> satellites[i].t_obs;
        fin >> s >> satellites[i].dt_s;
    }


    QPointF res = LocationDetector::getLocation(satellites);

    cout << "phi = " << toDegrees(res.x()).toStdString() << endl;
    cout << "lambda = " << toHours(res.y()).toStdString() << endl;

    return 0;
}

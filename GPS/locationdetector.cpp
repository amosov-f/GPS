#include "locationdetector.h"
#include "fundamental.h"
#include "locationshift.h"
#include "equationsystemsolver.h"
#include "table.h"
#include <cmath>
#include <iostream>
#include <QString>

using namespace std;
using namespace Fundamental;

LocationDetector::LocationDetector() {
}

QPointF LocationDetector::getLocation(const vector<SatelliteData>& satellites) {
    vector<pair<QVector3D, long double> > data(satellites.size());
    for (size_t i = 0; i < data.size(); ++i) {
        SatelliteData g = satellites[i];
        QVector3D pos = g.getSatelliteLocation();

        //distance to us
        double P = g.P + c * g.dt_s;

        data[i] = make_pair(pos, P);
    }

    data[0] = make_pair(QVector3D(21277632.227, 2624628.197, 15798292.012),
                        21245896.989);
    data[1] = make_pair(QVector3D(14136001.009, -7530688.663, 21144548.488),
                        21432492.103);
    data[2] = make_pair(QVector3D(6380947.343, 22063437.865, 13292356.357),
                        22216529.485);
    data[3] = make_pair(QVector3D(13667726.877, 9545209.321, 21346910.550),
                        20844087.288);

    Table initData(data.size() + 1, 7);
    initData[0][0] = "No.";
    initData[0][1] = "i";
    initData[0][2] = "X_i";
    initData[0][3] = "Y_i";
    initData[0][4] = "Z_i";
    initData[0][5] = "P_i^0";
    initData[0][6] = "dt_i^s";


    for (size_t i = 0; i < data.size(); ++i) {
        SatelliteData g = satellites[i];
        QVector3D pos = data[i].first;

        initData[i + 1][0] = QString().fromStdString(g.name);
        initData[i + 1][1] = QVariant().fromValue(i);
        initData[i + 1][2] = pos.x();
        initData[i + 1][3] = pos.y();
        initData[i + 1][4] = pos.z();
        initData[i + 1][5] = QVariant().fromValue((double)g.P);
        initData[i + 1][6] = QVariant().fromValue((double)g.dt_s);
    }

    cout << initData.toString().toStdString() << endl;

    Table initDist(data.size() + 1, 3);
    initDist[0][0] = "No.";
    initDist[0][1] = "i";
    initDist[0][2] = "P_i";
    for (size_t i = 0; i < data.size(); ++i) {
        initDist[i + 1][0] = QString().fromStdString(satellites[i].name);
        initDist[i + 1][1] = QVariant().fromValue(i);
        initDist[i + 1][2] = QVariant().fromValue((double)data[i].second);
    }

    cout << initDist.toString().toStdString() << endl;

    vector<long double> x0(4);
    //x0[0] = 2000000.312;
    //x0[1] = 1000000.271;
    //x0[2] = 5000000.781;
    //x0[3] = -0.0001;

    vector<long double> loc = EquationSystemSolver::solve(new LocationShift(data), x0);
    long double X = loc[0];
    long double Y = loc[1];
    long double Z = loc[2];

    cout.precision(10);
    cout << "X = " << X << endl;
    cout << "Y = " << Y << endl;
    cout << "Z = " << Z << endl;
    cout << "dt = " << loc[3] << endl << endl;

    long double e_sqr = 1.0 - pow(b / a, 2);
    long double e1_sqr = pow(a / b, 2) - 1.0;
    cout << "e^2 = " << e_sqr << endl;
    cout << "e1^2 = " << e1_sqr << endl << endl;

    long double lambda = atan2(Y, X);

    long double abs = sqrt(pow(X, 2) + pow(Y, 2));

    long double theta = atan2(a * Z, b * abs);
    cout << "theta = " << theta << endl << endl;

    long double phi = atan2(Z + e1_sqr * pow(sin(theta), 3) * b, abs - e_sqr * pow(cos(theta), 3) * a);

    return QPointF(phi, lambda);
}

#ifndef FUNCVECTOR_H
#define FUNCVECTOR_H

#include <vector>
#include <ostream>

using namespace std;

namespace FuncVector {

    vector<long double> operator +(const vector<long double>& v1, const vector<long double>& v2);
    void operator+=(vector<long double>& v, const vector<long double>& adj);

    vector<long double> operator -(const vector<long double>& v1, const vector<long double>& v2);
    void operator-=(vector<long double>& v1, const vector<long double>& v2);


    vector<long double> operator *(const vector<long double>& v, long double alpha);
    vector<long double> operator *(long double alpha, const vector<long double>& v);
    void operator *=(vector<long double>& v, long double alpha);

    long double operator *(const vector<long double>& v1, const vector<long double>& v2);
    long double abs(const vector<long double>& v);

    vector<long double> operator -(const vector<long double>& v);

    ostream& operator <<(ostream& stream, const vector<long double>& v);
}

#endif // FUNCVECTOR_H

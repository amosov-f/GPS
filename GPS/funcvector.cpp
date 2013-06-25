#include <cmath>
#include "funcvector.h"

vector<long double> FuncVector::operator +(const vector<long double>& v1, const vector<long double>& v2) {
    vector<long double> result(max(v1.size(), v2.size()));
    for (size_t i = 0; i < min(v1.size(), v2.size()); ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

void FuncVector::operator+=(vector<long double>& v, const vector<long double>& adj) {
    v = v + adj;
}

vector<long double> FuncVector::operator -(const vector<long double>& v1, const vector<long double>& v2) {
    vector<long double> result(max(v1.size(), v2.size()));
    for (size_t i = 0; i < min(v1.size(), v2.size()); ++i) {
        result[i] = v1[i] - v2[i];
    }
    return result;
}

void FuncVector::operator -=(vector<long double>& v, const vector<long double>& tog) {
    v = v - tog;
}

vector<long double> FuncVector::operator *(const vector<long double>& v, long double alpha) {
    vector<long double> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = alpha * v[i];
    }
    return result;
}

void FuncVector::operator *=(vector<long double>& v, long double alpha) {
    v = v * alpha;
}

//scalar multiply
long double FuncVector::operator *(const vector<long double>& v1, const vector<long double>& v2) {
    long double result = 0.0;
    for (size_t i = 0; i < min(v1.size(), v2.size()); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

long double FuncVector::abs(const vector<long double>& v) {
    return sqrt(v * v);
}

vector<long double> FuncVector::operator *(long double alpha, const vector<long double>& v) {
    return v * alpha;
}

vector<long double> FuncVector::operator -(const vector<long double>& v) {
    vector<long double> zero(v.size());
    return zero - v;
}

ostream& FuncVector::operator <<(ostream& stream, const vector<long double>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        stream << v[i] << " ";
    }
    return stream;
}

#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include "matrix.h"

class Function {
public:
    virtual long double get(const vector<long double>& x, size_t i) const = 0;

    vector<long double> get(const vector<long double>& x) const;

    long double derPar(const vector<long double>& x, size_t i, size_t k) const;

    Matrix jacobi(const vector<long double>& x) const;
};

#endif // FUNCTION_H

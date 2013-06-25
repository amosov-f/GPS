#include "function.h"

long double Function::derPar(const vector<long double>& x, size_t i, size_t k) const {
    const long double INC = 0.00000001;

    vector<long double> x1 = x;
    x1[k] += INC;
    return (get(x1, i) - get(x, i)) / INC;
}

vector<long double> Function::get(const vector<long double>& x) const {
    vector<long double> result(x.size());
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = get(x, i);
    }
    return result;
}

Matrix Function::jacobi(const vector<long double>& x) const {
    Matrix result(x.size(), x.size());
    for (size_t i = 0; i < result.nRow(); ++i) {
        for (size_t j = 0; j < result.nCol(); ++j) {
            result[i][j] = derPar(x, i, j);
        }
    }
    return result;
}

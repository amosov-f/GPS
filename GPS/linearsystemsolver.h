#ifndef LINEARSYSTEMSOLVER_H
#define LINEARSYSTEMSOLVER_H

#include <vector>
#include "matrix.h"

class LinearSystemSolver {
public:
    static vector<long double> solve(const Matrix& a, const vector<long double>& b);

private:
    LinearSystemSolver();
};

#endif // LINEARSYSTEMSOLVER_H

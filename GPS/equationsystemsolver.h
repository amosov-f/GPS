#ifndef EQUATIONSYSTEMSOLVER_H
#define EQUATIONSYSTEMSOLVER_H

#include "function.h"
#include <vector>

using namespace std;

class EquationSystemSolver {
public:
    static vector<long double> solve(Function* f, const vector<long double>& x0);

private:
    EquationSystemSolver();

    static const long double EPS = 0.000000000000000001L;
    static const int TIME_LIM = 50;
};

#endif // EQUATIONSYSTEMSOLVER_H

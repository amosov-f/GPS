#include "equationsystemsolver.h"
#include "funcvector.h"
#include "matrix.h"
#include "linearsystemsolver.h"
#include <cmath>
#include <iostream>

using namespace FuncVector;

EquationSystemSolver::EquationSystemSolver() {
}

vector<long double> EquationSystemSolver::solve(Function* f, const vector<long double>& x0) {
    vector<long double> cur = x0, prev;

    for (size_t t = 0; t < TIME_LIM; ++t) {
        prev = cur;
        cur = prev + LinearSystemSolver::solve(f->jacobi(prev), - f->get(prev));

        if (abs(cur - prev) < EPS) {
            return cur;
        }
    }

    return cur;
}

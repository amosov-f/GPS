#include "linearsystemsolver.h"
#include "funcvector.h"
#include <cmath>

using namespace FuncVector;

LinearSystemSolver::LinearSystemSolver() {
}

vector<long double> LinearSystemSolver::solve(const Matrix& a, const vector<long double>& b) {
    size_t n = a.nRow();
    Matrix a_ext(n, n + 1);
    vector<long double> x(n);
    vector<size_t> nums(n);

    for (size_t i = 0; i < n; ++i) {
        nums[i] = i;
        for (size_t j = 0; j < n; ++j) {
            a_ext[i][j] = a.get(i, j);
        }
        a_ext[i][n] = b[i];
    }

    for (size_t t = 0; t < n; ++t) {
        pair<size_t, size_t> posBest(t, t);
        for (size_t i = t; i < n; ++i) {
            for (size_t j = t; j < n; ++j) {
                if (abs(a_ext[i][j]) > a_ext[posBest.first][posBest.second]) {
                    posBest.first = i;
                    posBest.second = j;
                }
            }
        }
        a_ext.switchRow(t, posBest.first);
        a_ext.switchCol(t, posBest.second);
        swap(nums[t], nums[posBest.second]);
        a_ext.multiRow(t, 1.0 / a_ext[t][t]);
        for (size_t i = t + 1; i < n; ++i) {
            a_ext.addRow(i, t, -a_ext[i][t]);
        }
    }

    x[nums[n - 1]] = a_ext[n - 1][n];
    for (int i = n - 2; i >= 0; --i) {
        x[nums[i]] = a_ext[i][n];
        for (size_t j = i + 1; j < n; ++j) {
            x[nums[i]] -= a_ext[i][j] * x[nums[j]];
        }
    }

    return x;
}

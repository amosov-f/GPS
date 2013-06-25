#include "matrix.h"
#include "funcvector.h"

using namespace FuncVector;

Matrix::Matrix(size_t nRow, size_t nCol) {
    resize(nRow, nCol);
}

void Matrix::resize(size_t nRow, size_t nCol) {
    p.resize(nRow);
    for (size_t i = 0; i < p.size(); ++i) {
        p[i].resize(nCol);
    }
}

size_t Matrix::nRow() const {
    return p.size();
}

size_t Matrix::nCol() const {
    return p[0].size();
}

long double Matrix::get(size_t i, size_t j) const {
    return p[i][j];
}

vector<long double>& Matrix::operator[](size_t i) {
    return p[i];
}

void Matrix::switchRow(size_t i, size_t j) {
    swap(p[i], p[j]);
}

void Matrix::multiRow(size_t i, long double alpha) {
    if (alpha == 0.0) {
        return;
    }
    p[i] *= alpha;
}

void Matrix::addRow(size_t i, size_t j, long double alpha) {
    if (i == j) {
        return;
    }
    p[i] += p[j] * alpha;
}


void Matrix::switchCol(size_t i, size_t j) {
    for (size_t k = 0; k < nRow(); ++k) {
        swap(p[k][i], p[k][j]);
    }
}

void Matrix::multiCol(size_t i, long double alpha) {
    if (alpha == 0.0) {
        return;
    }
    for (size_t k = 0; k < nRow(); ++k) {
        p[k][i] *= alpha;
    }
}

void Matrix::addCol(size_t i, size_t j, long double alpha) {
    if (i == j) {
        return;
    }
    for (size_t k = 0; k < nRow(); ++k) {
        p[k][i] += p[k][j] * alpha;
    }
}


#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;

class Matrix {
public:
    Matrix(size_t nRow = 0, size_t nCol = 0);
    void resize(size_t nRow, size_t nCol);

    size_t nRow() const;
    size_t nCol() const;

    long double get(size_t i, size_t j) const;
    vector<long double>& operator[](size_t i);

    void switchRow(size_t i, size_t j);
    void multiRow(size_t i, long double alpha);
    void addRow(size_t i, size_t j, long double alpha);

    void switchCol(size_t i, size_t j);
    void multiCol(size_t i, long double j);
    void addCol(size_t i, size_t j, long double alpha);

private:
    vector<vector<long double> > p;
};

#endif // MATRIX_H

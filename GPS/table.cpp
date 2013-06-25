#include "table.h"
#include <qmath.h>

Table::Table(size_t height, size_t width) {
    cells = QVector<QVector<QVariant> >(height, QVector<QVariant>(width));
}

QVector<QVariant>& Table::operator [](size_t i) {
    return cells[i];
}

QString Table::toString() const {
    QString res;

    QVector<size_t> widths(cells[0].size());
    for (size_t i = 0; i < cells.size(); ++i) {
        for (size_t j = 0; j < cells[i].size(); ++j) {
            widths[j] = qMax(widths[j], (size_t)cells[i][j].toString().size());
        }
    }

    for (size_t i = 0; i < cells.size(); ++i) {
        for (size_t j = 0; j < cells[i].size(); ++j) {
            res += cells[i][j].toString();
            for (size_t k = 0; k < widths[j] - cells[i][j].toString().size(); ++k) {
                res += " ";
            }
            res += " |";
        }
        res += "\n";
    }

    return res;
}

#ifndef TABLE_H
#define TABLE_H

#include <QVector>
#include <QVariant>

class Table {
public:
    Table(size_t heigth, size_t width);

    QVector<QVariant>& operator [](size_t i);

    QString toString() const;

private:
    QVector<QVector<QVariant> > cells;
};

#endif // TABLE_H

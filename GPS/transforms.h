#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#include <QString>

namespace Transforms {
    const int BASE = 60;

    QString toDegrees(long double x);
    QString toHours(long double x);
}

#endif // TRANSFORMS_H

#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include "../qtupdatesystem_global.h"

namespace Utils {
    QString cleanPath(const QString &pathName);
    QString formatMs(qint64 millisec);

    QTUPDATESYSTEMSHARED_EXPORT QString xdeltaProgram();
    QTUPDATESYSTEMSHARED_EXPORT void setXdeltaProgram(const QString &program);

    QTUPDATESYSTEMSHARED_EXPORT QString lzmaProgram();
    QTUPDATESYSTEMSHARED_EXPORT void setLzmaProgram(const QString &program);
}
#endif // UTILS_H

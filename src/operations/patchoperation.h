#ifndef UPDATER_PATCHOPERATION_H
#define UPDATER_PATCHOPERATION_H

#include "addoperation.h"

class PatchOperation : public AddOperation
{
public:
    static const QString Action;
    virtual void fromJsonObjectV1(const QJsonObject &object) Q_DECL_OVERRIDE;
    void create(const QString &path, const QString &oldFilename, const QString &newFilename, const QString &tmpDirectory);
protected:
    virtual Status localDataStatus() Q_DECL_OVERRIDE;
    virtual void applyData() Q_DECL_OVERRIDE;
    virtual QString action() Q_DECL_OVERRIDE;
    virtual void fillJsonObjectV1(QJsonObject & object) Q_DECL_OVERRIDE;

    QString m_patchtype, m_localSha1;
    qint64 m_localSize;
};

#endif // UPDATER_PATCHOPERATION_H

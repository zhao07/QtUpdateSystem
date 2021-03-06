#include <QTest>
#include <QCoreApplication>
#include <QLoggingCategory>
#include <common/utils.h>

#include "testutils.h"
#include "tst_repository.h"
#include "tst_packager.h"
#include "tst_updater.h"
#include "tst_updatechain.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    TestUtils::cleanup = true;
#ifdef Q_OS_WIN
    Utils::setLzmaProgram(QString(SRCDIR)+ "../lzma.exe");
    Utils::setXdeltaProgram(QString(SRCDIR)+ "../xdelta3.exe");
#else
    Utils::setLzmaProgram(QString(SRCDIR)+ "../lzma");
#endif
    int ret = 0;

    QDir().mkpath(dataDir + "/rev1/empty_dir");
    QDir().mkpath(dataDir + "/rev1/empty_dir2");

    {
        TestPackager t;
        ret += QTest::qExec(&t, QStringList());
    }

    {
        TestRepository t;
        ret += QTest::qExec(&t, QStringList());
    }

    {
        TestUpdater t;
        ret += QTest::qExec(&t, QStringList());
    }

    {
        TestUpdateChain t;
        ret += QTest::qExec(&t, QStringList());
    }

    return ret;
}

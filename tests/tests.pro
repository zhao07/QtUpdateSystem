QT       += testlib
QT       -= gui

TARGET = tests
CONFIG   += console
CONFIG   -= app_bundle

CONFIG += c++11

TEMPLATE = app

DEFINES += SRCDIR=\\\"$$PWD/\\\"

SOURCES += \
    tst_packager.cpp \
    main.cpp \
    tst_updater.cpp \
    tst_updatechain.cpp \
    tst_repository.cpp \
    testutils.cpp

win32:CONFIG(release, debug|release) {
    subdir = release/
    dllext = .dll
}
else:win32:CONFIG(debug, debug|release) {
    subdir = debug/
    dllext = .dll
}
else:unix: {
    subdir =
    dllext = .so
}

LIBS += -L$$OUT_PWD/../src/$${subdir} -lQtUpdateSystem
LIBS += -L$$OUT_PWD/../QtLog/$${subdir} -lQtLog

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src
INCLUDEPATH += $$PWD/../QtLog
DEPENDPATH += $$PWD/../QtLog

HEADERS += \
    tst_packager.h \
    tst_updater.h \
    tst_updatechain.h \
    tst_repository.h \
    testutils.h

target.path = $$[top_builddir]/Install
INSTALLS += target

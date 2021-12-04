QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

CONFIG += console
QT -= gui

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    HealthPackModel.cpp \
    PenemyModel.cpp \
    Projectile.cpp \
    TileModel.cpp \
    ViewEnemy.cpp \
    ViewGraphical.cpp \
    ViewHealth.cpp \
    ViewHealthPack.cpp \
    ViewPenemy.cpp \
    ViewProtagonist.cpp \
    ViewText.cpp \
    ViewTile.cpp \
    ViewXenemy.cpp \
    XenemyModel.cpp \
    controllerViewSwitch.cpp \
    enemyModel.cpp \
    gameModel.cpp \
    main.cpp \
    mainwindow.cpp \
    myRect.cpp \
    pathplanner.cpp \
    protagonistModel.cpp

HEADERS += \
    HealthPackModel.h \
    PenemyModel.h \
    Projectile.h \
    TileModel.h \
    ViewEnemy.h \
    ViewGraphical.h \
    ViewHealth.h \
    ViewHealthPack.h \
    ViewPenemy.h \
    ViewProtagonist.h \
    ViewText.h \
    ViewTile.h \
    ViewXenemy.h \
    XenemyModel.h \
    controllerViewSwitch.h \
    enemyModel.h \
    gameModel.h \
    mainwindow.h \
    myRect.h \
    node.h \
    pathplanner.h \
    protagonistModel.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/./ -lworld

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

RESOURCES += \
    images.qrc

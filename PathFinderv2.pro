QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    node.cpp \
    pathplanner.cpp \
    HealthPackModel.cpp \
    PenemyModel.cpp \
    TileModel.cpp \
    ViewEnemy.cpp \
    ViewGraphical.cpp \
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
    protagonistModel.cpp \
    stringtextview.cpp \
    viewTiletext.cpp

HEADERS += \
    mainwindow.h \
    node.h \
    pathplanner.h \
    HealthPackModel.h \
    PenemyModel.h \
    TileModel.h \
    ViewEnemy.h \
    ViewGraphical.h \
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
    protagonistModel.h \
    stringtextview.h \
    viewTiletext.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
#Library


#unix:!macx: LIBS += -L$$PWD/../world_source_v4/ -lworld

#INCLUDEPATH += $$PWD/../world_source_v4
#DEPENDPATH += $$PWD/../world_source_v4

RESOURCES += \
    images.qrc



#unix:!macx: LIBS += -L$$PWD/mylib/ -lmylib

#INCLUDEPATH += $$PWD/mylib
#DEPENDPATH += $$PWD/mylib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../world_v4/release/ -lworld
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../world_v4/debug/ -lworld
else:unix: LIBS += -L$$PWD/../world_v4/ -lworld

INCLUDEPATH += $$PWD/../world_v4
DEPENDPATH += $$PWD/../world_v4

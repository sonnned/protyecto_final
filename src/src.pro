QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    background.cpp \
    bullet.cpp \
    enemy.cpp \
    firstlevelscene.cpp \
    gamemanager.cpp \
    main.cpp \
    game.cpp \
    menuscene.cpp \
    player.cpp \
    playerscore.cpp \
    secondlevelscene.cpp \
    spacecraft.cpp

HEADERS += \
    background.h \
    bullet.h \
    enemy.h \
    firstlevelscene.h \
    game.h \
    gamemanager.h \
    macros.h \
    menuscene.h \
    player.h \
    playerscore.h \
    secondlevelscene.h \
    spacecraft.h

FORMS += \
    game.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    backgrounds.qrc \
    bullet.qrc \
    charactesSprites.qrc \
    enemies.qrc \
    fonts.qrc

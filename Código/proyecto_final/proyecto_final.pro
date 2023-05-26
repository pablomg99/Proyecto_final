QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    escena.cpp \
    granjero.cpp \
    main.cpp \
    mainwindow.cpp \
    obstaculo.cpp \
    ovni.cpp \
    sprite.cpp \
    vaca.cpp

HEADERS += \
    escena.h \
    granjero.h \
    mainwindow.h \
    obstaculo.h \
    ovni.h \
    sprite.h \
    vaca.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc

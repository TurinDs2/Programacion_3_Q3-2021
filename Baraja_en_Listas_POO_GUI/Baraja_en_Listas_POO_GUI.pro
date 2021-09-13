QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clsBaraja.cpp \
    clsCarta.cpp \
    clsCasino.cpp \
    clsEmpleado.cpp \
    clsJugador.cpp \
    clsPersona.cpp \
    main.cpp \
    cframe.cpp

HEADERS += \
    Lista.h \
    Nodo.h \
    cframe.h \
    clsBaraja.h \
    clsCarta.h \
    clsCasino.h \
    clsEmpleado.h \
    clsJugador.h \
    clsPersona.h

FORMS += \
    cframe.ui

MYSQL_LIBS = -lmysqld
QMAKE_CXXFLAGS += -std=gnu++11

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

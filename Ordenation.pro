TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L/usr/lib -lsfml-graphics -lsfml-window -lsfml-system -lpthread
INCLUDEPATH += /usr/lib/
CONFIG += c++11

SOURCES += main.cpp

HEADERS += \
    player.h \
    sortview.h

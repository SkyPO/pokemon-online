#-------------------------------------------------
#
# Project created by QtCreator 2012-11-28T21:46:22
#
#-------------------------------------------------

QT       += core network xml gui

TARGET = RelayStation
DESTDIR = ../../bin
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -L../../bin \
    -lutilities \
    -lpokemonlib \
    -lbattlelib \
    -lqtwebsocket \
    -lqjson

SOURCES += main.cpp \
    relaystation.cpp \
    ../Teambuilder/network.cpp \
    dualwielder.cpp \
    pokemontojson.cpp

HEADERS += \
    relaystation.h \
    ../Teambuilder/network.h \
    dualwielder.h \
    pokemontojson.h

QMAKE_CXXFLAGS += "-std=c++0x -U__STRICT_ANSI__"

include(../Shared/Common.pri)

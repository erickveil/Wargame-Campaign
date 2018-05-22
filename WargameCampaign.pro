#-------------------------------------------------
#
# Project created by QtCreator 2018-05-21T14:55:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WargameCampaign
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dice.cpp \
    randomtable.cpp \
    tableentry.cpp \
    npcgenerator.cpp

HEADERS  += mainwindow.h \
    dice.h \
    randomtable.h \
    tableentry.h \
    npcgenerator.h

FORMS    += mainwindow.ui

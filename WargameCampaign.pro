#-------------------------------------------------
#
# Project created by QtCreator 2018-05-21T14:55:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WargameCampaign
TEMPLATE = app

CONFIG += c++14


SOURCES += main.cpp\
        mainwindow.cpp \
    dice.cpp \
    randomtable.cpp \
    tableentry.cpp \
    npcgenerator.cpp \
    battleresolve.cpp \
    politicalnpc.cpp

HEADERS  += mainwindow.h \
    dice.h \
    randomtable.h \
    tableentry.h \
    npcgenerator.h \
    battleresolve.h \
    politicalnpc.h \
    libtcod-1.5.1/include/bresenham.h \
    libtcod-1.5.1/include/bresenham.hpp \
    libtcod-1.5.1/include/bsp.h \
    libtcod-1.5.1/include/bsp.hpp \
    libtcod-1.5.1/include/color.h \
    libtcod-1.5.1/include/color.hpp \
    libtcod-1.5.1/include/console_types.h \
    libtcod-1.5.1/include/console.h \
    libtcod-1.5.1/include/console.hpp \
    libtcod-1.5.1/include/fov_types.h \
    libtcod-1.5.1/include/fov.h \
    libtcod-1.5.1/include/fov.hpp \
    libtcod-1.5.1/include/heightmap.h \
    libtcod-1.5.1/include/heightmap.hpp \
    libtcod-1.5.1/include/image.h \
    libtcod-1.5.1/include/image.hpp \
    libtcod-1.5.1/include/lex.h \
    libtcod-1.5.1/include/lex.hpp \
    libtcod-1.5.1/include/libtcod_int.h \
    libtcod-1.5.1/include/libtcod.h \
    libtcod-1.5.1/include/libtcod.hpp \
    libtcod-1.5.1/include/list.hpp \
    libtcod-1.5.1/include/mersenne_types.h \
    libtcod-1.5.1/include/mersenne.h \
    libtcod-1.5.1/include/mersenne.hpp \
    libtcod-1.5.1/include/mouse_types.h \
    libtcod-1.5.1/include/mouse.h \
    libtcod-1.5.1/include/mouse.hpp \
    libtcod-1.5.1/include/namegen.h \
    libtcod-1.5.1/include/namegen.hpp \
    libtcod-1.5.1/include/noise_defaults.h \
    libtcod-1.5.1/include/noise.h \
    libtcod-1.5.1/include/noise.hpp \
    libtcod-1.5.1/include/parser.h \
    libtcod-1.5.1/include/parser.hpp \
    libtcod-1.5.1/include/path.h \
    libtcod-1.5.1/include/path.hpp \
    libtcod-1.5.1/include/sys.h \
    libtcod-1.5.1/include/sys.hpp \
    libtcod-1.5.1/include/tree.h \
    libtcod-1.5.1/include/tree.hpp \
    libtcod-1.5.1/include/txtfield.h \
    libtcod-1.5.1/include/txtfield.hpp \
    libtcod-1.5.1/include/wrappers.h \
    libtcod-1.5.1/include/zip.h \
    libtcod-1.5.1/include/zip.hpp \
    libtcod-1.5.1/include/gui/button.hpp \
    libtcod-1.5.1/include/gui/container.hpp \
    libtcod-1.5.1/include/gui/flatlist.hpp \
    libtcod-1.5.1/include/gui/gui.hpp \
    libtcod-1.5.1/include/gui/hbox.hpp \
    libtcod-1.5.1/include/gui/image.hpp \
    libtcod-1.5.1/include/gui/label.hpp \
    libtcod-1.5.1/include/gui/radiobutton.hpp \
    libtcod-1.5.1/include/gui/slider.hpp \
    libtcod-1.5.1/include/gui/statusbar.hpp \
    libtcod-1.5.1/include/gui/textbox.hpp \
    libtcod-1.5.1/include/gui/togglebutton.hpp \
    libtcod-1.5.1/include/gui/toolbar.hpp \
    libtcod-1.5.1/include/gui/vbox.hpp \
    libtcod-1.5.1/include/gui/widget.hpp \
    libtcod-1.5.1/include/list.h

FORMS    += mainwindow.ui

INCLUDEPATH += libtcod-1.5.1/include
INCLUDEPATH += libtcod-1.5.1/include/gui

LIBS += -L"/home/anon/src/Wargame-Campaign/libtcod-1.5.1/" -ltcod
LIBS += -L"/home/anon/src/Wargame-Campaign/libtcod-1.5.1/" -ltcodxx
LIBS += -L"/home/anon/src/Wargame-Campaign/libtcod-1.5.1/" -ltcodgui



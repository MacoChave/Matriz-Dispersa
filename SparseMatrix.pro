QT += core
QT -= gui

CONFIG += c++11

TARGET = SparseMatrix
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Matriz/Tad/tadcolumn.cpp \
    Matriz/Tad/tadrow.cpp

HEADERS += \
    Matriz/Cabecera/list.h \
    Matriz/Cabecera/node.h \
    Matriz/Tad/tadcolumn.h \
    Matriz/Tad/tadrow.h

QT += core
QT -= gui

CONFIG += c++11

TARGET = SparseMatrix
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Matriz/Tad/tadcolumn.cpp \
    Matriz/Tad/tadrow.cpp \
    Matriz/Interno/nodomatriz.cpp \
    Matriz/Interno/filamatriz.cpp \
    Matriz/Interno/columnamatriz.cpp \
    Matriz/Tad/tadmatrixnode.cpp \
    Matriz/Interno/matrixcolumn.cpp \
    Matriz/Interno/matrixnode.cpp \
    Matriz/Interno/matrixrow.cpp \
    Matriz/Interno/nodecolumnlist.cpp \
    Matriz/Interno/noderowlist.cpp \
    Matriz/Interno/columnlist.cpp \
    Matriz/Interno/rowlist.cpp \
    Matriz/Tad/tadcolumnlist.cpp \
    Matriz/Tad/tadrowlist.cpp

HEADERS += \
    Matriz/Cabecera/list.h \
    Matriz/Cabecera/node.h \
    Matriz/Tad/tadcolumn.h \
    Matriz/Tad/tadrow.h \
    Matriz/Interno/filamatriz.h \
    Matriz/Tad/tadmatrixnode.h \
    Matriz/Interno/matrixnode.h \
    Matriz/Interno/matrixrow.h \
    Matriz/Interno/columnlist.h \
    Matriz/Interno/rowlist.h

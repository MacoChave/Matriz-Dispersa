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
    Matriz/Tad/tadmatrixnode.cpp \
    Matriz/Interno/matrixnode.cpp \
    Matriz/Interno/columnlist.cpp \
    Matriz/Interno/rowlist.cpp \
    Matriz/matrix.cpp

HEADERS += \
    Matriz/Tad/tadcolumn.h \
    Matriz/Tad/tadrow.h \
    Matriz/Tad/tadmatrixnode.h \
    Matriz/Interno/matrixnode.h \
    Matriz/Interno/columnlist.h \
    Matriz/Interno/rowlist.h \
    Cabecera/list.h \
    Cabecera/node.h \
    Matriz/matrix.h \
    Matriz/MatrixHeader/headercolumn.h \
    Matriz/MatrixHeader/headerrow.h

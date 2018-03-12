#ifndef MATRIZ_H
#define MATRIZ_H
#include "Cabecera/list.h"
#include "Tad/tadcolumn.h"
#include "Tad/tadrow.h"
#include <QFile>
#include <QTextStream>
#include <QtDebug>

class Matrix
{
    List<TADColumn *> *headerColumns;
    List<TADRow *> *headerRows;

    QString getRankRow(MatrixNode *currentNode);
public:
    Matrix();
    ~Matrix();

    /* MODIFICADORES */
    void insert(TADMatrixNode *value);
    void erase(int x, int y);
    MatrixNode *get(int x, int y);
    void edit(int x, int y, TADMatrixNode *value);
    MatrixNode *remove(int x, int y);

    /* OPERACIONES */
    void graph(QString filename);
};

#endif // MATRIZ_H

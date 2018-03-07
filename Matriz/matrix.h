#ifndef MATRIZ_H
#define MATRIZ_H
#include "Cabecera/list.h"
#include "Tad/tadcolumn.h"
#include "Tad/tadrow.h"

class Matrix
{
    List<TADColumn *> headerColumns;
    List<TADRow *> headerRows;
public:
    Matrix();
    ~Matrix();

    /* MODIFICADORES */
    void insert(TADMatrixNode *value);

    /* OPERACIONES */
    void graph(QString filename);
};

#endif // MATRIZ_H

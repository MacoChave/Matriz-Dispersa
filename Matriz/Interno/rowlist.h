#ifndef ROWLIST_H
#define ROWLIST_H
#include "matrixnode.h"

class RowList
{
    int count;
    MatrixNode *head;
    MatrixNode *tail;

    MatrixNode *insert(MatrixNode *current, TADMatrixNode *value);
    MatrixNode *get(MatrixNode *current, TADMatrixNode *value);
public:
    RowList();
    ~RowList();

    /* CAPACIDAD */
    bool isEmpty();
    int size();
    void clear();

    /* MODIFICADORES */
    MatrixNode *push_front(TADMatrixNode *value);
    MatrixNode *push_back(TADMatrixNode *value);
    MatrixNode *insert(TADMatrixNode *value);
    MatrixNode *removeFirst();
    MatrixNode *removeLast();
    MatrixNode *removeOne(TADMatrixNode *value);

    /* OPERACIONES */
    MatrixNode *fist();
    MatrixNode *last();
    TADMatrixNode *front();
    TADMatrixNode *back();
    MatrixNode *get(TADMatrixNode *value);
    void graph(QString filename);
};

#endif // FILAMATRIZ_H

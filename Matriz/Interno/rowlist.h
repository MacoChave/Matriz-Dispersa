#ifndef ROWLIST_H
#define ROWLIST_H
#include "matrixnode.h"

class RowList
{
    MatrixNode *first;
    MatrixNode *last;
public:
    RowList();
    ~RowList();
};

#endif // FILAMATRIZ_H

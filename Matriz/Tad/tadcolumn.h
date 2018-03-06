#ifndef TADCOLUMN_H
#define TADCOLUMN_H
#include <QString>
#include "Matriz/matrixnode.h"
#include "tadmatrixnode.h"

class TADColumn
{
    int i;
    MatrixNode<TADMatrixNode *> *matrixNode;
public:
    TADColumn();
    TADColumn(int _i);
    ~TADColumn();

    int getI();
    int compare(TADColumn *column);
    QString toString();
    QString getNodeName();
};

#endif // TADCOLUMN_H

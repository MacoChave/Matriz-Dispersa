#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include "../Tad/tadmatrixnode.h"

class MatrixNode
{
    TADMatrixNode *data;
    MatrixNode *preview;
    MatrixNode *next;
    MatrixNode *top;
    MatrixNode *bottom;
public:
    MatrixNode();
    MatrixNode(TADMatrixNode *value);
    ~MatrixNode();
    MatrixNode *getPreview();
    void setPreview(MatrixNode *value);
    MatrixNode *getNext();
    void setNext(MatrixNode *value);
    MatrixNode *getTop();
    void setTop(MatrixNode *value);
    MatrixNode *getBottom();
    void setBottom(MatrixNode *value);

    int compareColumn(TADMatrixNode *value);
    int compareRow(TADMatrixNode *value);
    int compareLevel(TADMatrixNode *value);
    QString getNodeName();
    QString toString();
};

#endif // NODOMATRIZ_H

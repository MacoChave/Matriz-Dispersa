#ifndef TADROW_H
#define TADROW_H
#include "../Interno/rowlist.h"

class TADRow
{
    int j;
    RowList *internalRow;
public:
    TADRow();
    TADRow(int _j);
    ~TADRow();

    int getJ();
    int compare(TADRow *row);
    RowList *getInternalRow();
    MatrixNode *addInternalRow(MatrixNode *value);
    QString toString();
    QString getNodeName();
    QString createNode();
    QString pointNode(TADRow *next);
};

#endif // TADROW_H

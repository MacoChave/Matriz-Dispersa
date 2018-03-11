#ifndef TADCOLUMN_H
#define TADCOLUMN_H
#include "../Interno/columnlist.h"

class TADColumn
{
    int i;
    ColumnList *internalColumn;
public:
    TADColumn();
    TADColumn(int _i);
    ~TADColumn();

    int getI();
    int compare(TADColumn *column);
    ColumnList *getInternalColumn();
    MatrixNode *addInternalColumn(TADMatrixNode *value);
    QString toString();
    QString getNodeName();
    QString createNode();
    QString pointNode(TADColumn *next);
};

#endif // TADCOLUMN_H

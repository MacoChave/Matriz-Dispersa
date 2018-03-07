#ifndef TADROW_H
#define TADROW_H
#include <QString>
#include "../Interno/rowlist.h"

class TADRow
{
    int j;
    RowList *rowInside;
public:
    TADRow();
    TADRow(int _j);
    ~TADRow();

    int getJ();
    int compare(TADRow *row);
    RowList *getRowInside();
    void addRowInside(MatrixNode *value);
    QString toString();
    QString getNodeName();
};

#endif // TADROW_H

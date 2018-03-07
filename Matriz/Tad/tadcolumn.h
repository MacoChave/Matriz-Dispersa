#ifndef TADCOLUMN_H
#define TADCOLUMN_H
#include <QString>
#include "../Interno/columnlist.h"

class TADColumn
{
    int i;
    ColumnList *columnInside;
public:
    TADColumn();
    TADColumn(int _i);
    ~TADColumn();

    int getI();
    int compare(TADColumn *column);
    ColumnList *getColumnInside();
    void addColumnInside(); //TAD Nodo Matriz
    QString toString();
    QString getNodeName();
};

#endif // TADCOLUMN_H

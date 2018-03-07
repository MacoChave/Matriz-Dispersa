#include "tadcolumn.h"

TADColumn::TADColumn()
{
    i = 0;
    columnInside = new ColumnList();
}

TADColumn::TADColumn(int _i)
{
    i = _i;
    columnInside = new ColumnList();
}

TADColumn::~TADColumn()
{
    i = 0;
    if (columnInside != NULL)
        delete columnInside;
    columnInside = NULL;
}

int TADColumn::getI()
{
    return i;
}

int TADColumn::compare(TADColumn *column)
{
    if (i > column->getI())
        return 1;
    if (i < column->getI())
        return -1;

    return 0;
}

ColumnList *TADColumn::getColumnInside()
{
    return columnInside;
}

MatrixNode *TADColumn::addColumnInside(TADMatrixNode *value)
{
    return columnInside->insert(value);
}

QString TADColumn::toString()
{
    QString text("Column\\n");
    text.append(QString::number(i));

    return text;
}

QString TADColumn::getNodeName()
{
    QString name("node");
    name.append(QString::number(i));

    return name;
}

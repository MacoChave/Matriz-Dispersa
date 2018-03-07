#include "tadrow.h"

TADRow::TADRow()
{
    j = 0;
    rowInside = new RowList();
}

TADRow::TADRow(int _j)
{
    j = _j;
    rowInside = new RowList();
}

TADRow::~TADRow()
{
    j = 0;
    if (rowInside != NULL)
        delete rowInside;
    rowInside = NULL;
}

int TADRow::getJ()
{
    return j;
}

int TADRow::compare(TADRow *row)
{
    if (j > row->getJ())
        return 1;
    if (j < row->getJ())
        return -1;

    return 0;
}

RowList *TADRow::getRowInside()
{
    return rowInside;
}

void TADRow::addRowInside(MatrixNode *value)
{
    rowInside->insert(value);
}

QString TADRow::toString()
{
    QString text("Row\\n");
    text.append(QString::number(j));

    return text;
}

QString TADRow::getNodeName()
{
    QString name("node");
    name.append(QString::number(j));

    return name;
}

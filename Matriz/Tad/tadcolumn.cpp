#include "tadcolumn.h"

TADColumn::TADColumn()
{
    i = 0;
}

TADColumn::TADColumn(int _i)
{
    i = _i;
}

TADColumn::~TADColumn()
{
    i = 0;
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

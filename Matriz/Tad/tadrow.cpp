#include "tadrow.h"

TADRow::TADRow()
{
    j = 0;
}

TADRow::TADRow(int _j)
{
    j = _j;
}

TADRow::~TADRow()
{
    j = 0;
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

#include "tadmatrixnode.h"

TADMatrixNode::TADMatrixNode()
{
    column = row = 0;
}

TADMatrixNode::TADMatrixNode(int _column, int _row)
{
    column = _column;
    row = _row;
}

TADMatrixNode::~TADMatrixNode()
{
    column = row = 0;
}

int TADMatrixNode::getColumnValue()
{
    return column;
}

int TADMatrixNode::getRowValue()
{
    return row;
}

int TADMatrixNode::getLevel()
{
    return level;
}

void TADMatrixNode::setColumnValue(int value)
{
    column = value;
}

void TADMatrixNode::setRowValue(int value)
{
    row = value;
}

void TADMatrixNode::setLevel(int value)
{
    level = value;
}

int TADMatrixNode::compareColumn(TADMatrixNode *value)
{
    if (column > value->getColumnValue())
        return 1;

    if (column < value->getColumnValue())
        return -1;

    return 0;
}

int TADMatrixNode::compareRow(TADMatrixNode *value)
{
    if (row > value->getRowValue())
        return 1;

    if (row < value->getRowValue())
        return -1;

    return 0;
}

int TADMatrixNode::compareLevel(TADMatrixNode *value)
{
    if (level > value->getLevel())
        return 1;

    if (row < value->getLevel())
        return -1;

    return 0;
}

QString TADMatrixNode::getNodeName()
{
    QString name("node");
    name.append(QString::number(column));
    name.append(QString::number(row));
    name.append(QString::number(level));

    return name;
}

QString TADMatrixNode::toString()
{
    QString name;
    name.append("(");
    name.append(QString::number(column));
    name.append(" - ");
    name.append(QString::number(row));
    name.append(" - ");
    name.append(QString::number(level));
    name.append(")");

    return name;
}

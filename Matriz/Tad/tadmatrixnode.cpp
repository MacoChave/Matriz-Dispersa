#include "tadmatrixnode.h"

TADMatrixNode::TADMatrixNode()
{
    column = row = level = 0;
}

TADMatrixNode::TADMatrixNode(int _column, int _row)
{
    column = _column;
    row = _row;
    level = 0;
}

TADMatrixNode::~TADMatrixNode()
{
    column = row = level = 0;
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
    QString str;
    QTextStream name(&str);
    name << "node_";
    name << QString::number(column) << "_";
    name << QString::number(row) << "_";
    name << QString::number(level);

    return str;
}

QString TADMatrixNode::toString()
{
    QString str;
    QTextStream name(&str);
    name << "(";
    name << QString::number(column) << ", " << QString::number(row) << ", " << QString::number(level);
    name << ")";

    return str;
}

QString TADMatrixNode::createNode()
{
    QString str;
    QTextStream createdNode(&str);
    createdNode << "\t" << getNodeName();
    createdNode << " [label = \"" << toString() << "\"];\n";

    return str;
}

QString TADMatrixNode::pointNode(TADMatrixNode *next)
{
    QString str;
    QTextStream nodePointers(&str);
    if (next != NULL)
    {
        nodePointers << "\t" << getNodeName() << " -> " << next->getNodeName() << ";\n";
        nodePointers << "\t" << next->getNodeName() << " -> " << getNodeName() << ";\n";
    }

    return str;
}

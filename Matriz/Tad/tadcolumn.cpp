#include "tadcolumn.h"

TADColumn::TADColumn()
{
    i = 0;
    internalColumn = new ColumnList();
}

TADColumn::TADColumn(int _i)
{
    i = _i;
    internalColumn = new ColumnList();
}

TADColumn::~TADColumn()
{
    i = 0;
    delete internalColumn;
    internalColumn = NULL;
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

ColumnList *TADColumn::getInternalColumn()
{
    return internalColumn;
}

MatrixNode *TADColumn::addInternalColumn(TADMatrixNode *value)
{
    MatrixNode *node = new MatrixNode(value);
    return internalColumn->insert(node);
}

MatrixNode *TADColumn::addInternalColumn(MatrixNode *value)
{
    return internalColumn->insert(value);
}

QString TADColumn::toString()
{
    QString text("Column\\n");
    text.append(QString::number(i));

    return text;
}

QString TADColumn::getNodeName()
{
    QString name("Column");
    name.append(QString::number(i));

    return name;
}

QString TADColumn::createNode()
{
    QString str;
    QTextStream createdNode(&str);
    createdNode << "\t" << getNodeName();
    createdNode << " [label = \"" << toString() << "\"];\n";

    return str;
}

QString TADColumn::pointNode(TADColumn *next)
{
    QString str;
    QTextStream nodePointers(&str);
    if (next != NULL)
    {
        nodePointers << "\t" << getNodeName() << " -> " << next->getNodeName() << ";\n";
        nodePointers << "\t" << next->getNodeName() << " -> " << getNodeName() << ";\n";
    }

    if (! internalColumn->isEmpty())
    {
        nodePointers << "\t" << getNodeName() << " -> " << internalColumn->front()->getNodeName() << ";\n";
        nodePointers << internalColumn->graph() << "\n";
    }

    return str;
}

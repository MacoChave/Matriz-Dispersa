#include "tadrow.h"

TADRow::TADRow()
{
    j = 0;
    internalRow = new RowList();
}

TADRow::TADRow(int _j)
{
    j = _j;
    internalRow = new RowList();
}

TADRow::~TADRow()
{
    j = 0;
    delete internalRow;
    internalRow = NULL;
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

RowList *TADRow::getInternalRow()
{
    return internalRow;
}

MatrixNode *TADRow::addInternalRow(MatrixNode *value)
{
    return internalRow->insert(value);
}

QString TADRow::toString()
{
    QString text("Row\\n");
    text.append(QString::number(j));

    return text;
}

QString TADRow::getNodeName()
{
    QString name("Row");
    name.append(QString::number(j));

    return name;
}

QString TADRow::createNode()
{
    QString str;
    QTextStream createdNode(&str);
    createdNode << "\t" << getNodeName();
    createdNode << " [label = \"" << toString() << "\"];\n";

    return str;
}

QString TADRow::pointNode(TADRow *next)
{
    QString str;
    QTextStream nodePointers(&str);
    if (next != NULL)
    {
        nodePointers << "\t" << getNodeName() << " -> " << next->getNodeName() << ";\n";
        nodePointers << "\t" << next->getNodeName() << " -> " << getNodeName() << ";\n";
    }

    if (! internalRow->isEmpty())
    {
        nodePointers << "\t" << getNodeName() << " -> " << internalRow->front()->getNodeName() << ";\n";
        nodePointers << internalRow->graph() << "\n";
    }

    return str;
}

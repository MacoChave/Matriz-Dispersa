#ifndef TADMATRIXNODE_H
#define TADMATRIXNODE_H
#include <QString>
#include <QTextStream>

class TADMatrixNode
{
    int column;
    int row;
    int level;
public:
    TADMatrixNode();
    TADMatrixNode(int _column, int _row);
    ~TADMatrixNode();

    int getColumnValue();
    int getRowValue();
    int getLevel();
    void setColumnValue(int value);
    void setRowValue(int value);
    void setLevel(int value);

    int compareColumn(TADMatrixNode *value);
    int compareRow(TADMatrixNode *value);
    int compareLevel(TADMatrixNode *value);
    QString getNodeName();
    QString toString();
    QString createNode();
    QString pointNode(TADMatrixNode *next);
};

#endif // TADMATRIXNODE_H

#ifndef TADROW_H
#define TADROW_H
#include <QString>

class TADRow
{
    int j;
public:
    TADRow();
    TADRow(int _j);
    ~TADRow();

    int getJ();
    int compare(TADRow *row);
    QString toString();
    QString getNodeName();
};

#endif // TADROW_H

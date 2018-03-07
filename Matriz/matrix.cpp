#include "matrix.h"

Matrix::Matrix()
{
    headerColumns = new List<TADColumn *>();
    headerRows = new List<TADRow *>();
}

Matrix::~Matrix()
{
}

void Matrix::insert(TADMatrixNode *value)
{
    TADColumn *column = new TADColumn(value->getColumnValue());
    TADRow *row = new TADRow(value->getRowValue());
    MatrixNode *node = NULL;

    headerColumns.insert(column);
    headerRows.insert(row);

    node = column->addColumnInside(value);
    row->addRowInside(node);
}

void Matrix::graph(QString filename)
{
}

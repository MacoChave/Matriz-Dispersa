#include <QCoreApplication>
#include "Matriz/matrix.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Matrix *sparseMatrix = new Matrix();
    sparseMatrix->insert(new TADMatrixNode(10,10));

    return a.exec();
}

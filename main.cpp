#include <QCoreApplication>
#include <iostream>
#include "Matriz/matrix.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Matrix *sparseMatrix = new Matrix();
    int opcion = 0;
    int x = 0;
    int y = 0;

    do {
        cout << "MATRIZ DISPERSA" << endl;
        cout << "[0] Salir" << endl;
        cout << "[1] Insertar" << endl;
        cout << "[2] Eliminar" << endl;
        cout << "[3] Buscar" << endl;
        cout << "[4] Editar" << endl;

        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            cout << "-----> Insertar <-----" << endl;
            cout << "Coordenada x? ";
            cin >> x;

            cout << "Coordenada y? ";
            cin >> y;

            sparseMatrix->insert(new TADMatrixNode(x, y));

            break;
        }
        case 2:
        {
            cout << "-----> Eliminar <-----" << endl;
            cout << "Coordenada x? ";
            cin >> x;

            cout << "Coordenada y? ";
            cin >> y;

            break;
        }
        case 3:
        {
            cout << "-----> Buscar <-----" << endl;

            cout << "Coordenada x? ";
            cin >> x;

            cout << "Coordenada y? ";
            cin >> y;

            MatrixNode *node = sparseMatrix->get(x, y);
            if (node != NULL)
                cout << "Se encontró el nodo :)" << endl;
            else
                cout << "No existe tal nodo :(" << endl;

            break;
        }
        case 4:
        {
            int nuevoX = 0;
            int nuevoY = 0;

            cout << "-----> Editar <-----" << endl;

            cout << "Coordenada x? ";
            cin >> x;
            cout << "Nueva coordenada x? ";
            cin >> nuevoX;

            cout << "Coordenada y? ";
            cin >> y;
            cout << "Nueva coordenada y? ";
            cin >> nuevoY;

            break;
        }
        default:
        {
            cout << "Opción no disponible :(" << endl;
        }
        }

        sparseMatrix->graph("MatrizDispersa");
    } while (opcion != 0);

    delete sparseMatrix;

    return 0;
}

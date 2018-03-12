#include "matrix.h"

QString Matrix::getRankRow(MatrixNode *currentNode)
{
    QString texto;
    while (currentNode != NULL)
    {
        texto.append("; ");
        texto.append(currentNode->getNodeName());

        currentNode = currentNode->getNext();
    }

    return texto;
}

Matrix::Matrix()
{
    headerColumns = new List<TADColumn *>();
    headerRows = new List<TADRow *>();
}

Matrix::~Matrix()
{
    qInfo() << "Limpiando memoria de matriz :)";
    delete headerColumns;
    delete headerRows;
    qInfo() << "Memoria de matriz limpia :D";
}

void Matrix::insert(TADMatrixNode *value)
{
    TADColumn *column = new TADColumn(value->getColumnValue());
    TADRow *row = new TADRow(value->getRowValue());
    MatrixNode *node = new MatrixNode(value);

    Node<TADColumn *> *nodeColumn = headerColumns->insert(column);
    Node<TADRow *> *nodeRow = headerRows->insert(row);

    if (nodeColumn->getData()->addInternalColumn(node) != NULL)
    {
        if (nodeRow->getData()->addInternalRow(node) != NULL)
            qInfo() << "Se insertó correctamente el nodo :)";
        else
        {
            nodeColumn->getData()->getInternalColumn()->removeOne(value);
            qWarning() << "No se pudo insertar el nodo en la fila seleccionada :(";
        }
    }
    else
    {
        delete node;
        node = NULL;
        qWarning() << "No se insertó el nodo :(";
    }
}

void Matrix::erase(int x, int y)
{
    MatrixNode *node = remove(x, y);
    if (node != NULL)
    {
        qInfo() << "Nodo encontrado :)";
        delete node;
        node = NULL;
        qInfo() << "Nodo eliminado :D";
    }
    else
        qWarning() << "No se encontró el nodo :(";
}

MatrixNode *Matrix::get(int x, int y)
{
    TADColumn *tadColumn = new TADColumn(x);
    TADMatrixNode *tadMatrixNode = new TADMatrixNode(x, y);
    MatrixNode *node = NULL;

    Node<TADColumn *> *nodeColumn = headerColumns->get(tadColumn);
    if (nodeColumn != NULL)
        node = nodeColumn->getData()->getInternalColumn()->get(tadMatrixNode);

    delete tadColumn;
    delete tadMatrixNode;
    tadColumn = NULL;
    tadMatrixNode = NULL;

    return node;
}

void Matrix::edit(int x, int y, TADMatrixNode *value)
{
    MatrixNode *node = remove(x, y);

    node->getData()->setColumnValue(value->getColumnValue());
    node->getData()->setRowValue(value->getRowValue());
    node->getData()->setLevel(value->getLevel());

    TADColumn *column = new TADColumn(value->getColumnValue());
    TADRow *row = new TADRow(value->getRowValue());

    Node<TADColumn *> *nodeColumn = headerColumns->insert(column);
    Node<TADRow *> *nodeRow = headerRows->insert(row);

    if (nodeColumn->getData()->addInternalColumn(node) != NULL)
    {
        if (nodeRow->getData()->addInternalRow(node) != NULL)
            qInfo() << "Se modificó el nodo :)";
        else
        {
            nodeColumn->getData()->getInternalColumn()->removeOne(value);
            qWarning() << "No se pudo reposicionar el nodo en la fila :(";
        }
    }
    else
    {
        delete node;
        node = NULL;
        qWarning() << "No se pudo reposicionar el nodo en la columna :(";
    }

    delete value;
    value = NULL;
}

MatrixNode *Matrix::remove(int x, int y)
{
    Node<TADColumn *> *nodeColumn = headerColumns->get(new TADColumn(x));
    Node<TADRow *> *nodeRow = headerRows->get(new TADRow(y));
    TADMatrixNode *tadNode = new TADMatrixNode(x, y);
    MatrixNode *node = NULL;

    node = nodeColumn->getData()->getInternalColumn()->removeOne(tadNode);

    if (node != NULL)
    {
        nodeRow->getData()->getInternalRow()->removeOne(tadNode);

        return node;
    }
    else
        return NULL;

    delete tadNode;
    tadNode = NULL;
}

void Matrix::graph(QString filename)
{
    if (headerColumns->isEmpty() && headerRows->isEmpty())
        return;

    QFile file(filename + ".dot");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "digraph " << filename << " {\n";
        out << "\tnode[shape = box]\n";
        flush(out);

        out << "\tnodeMatrix [label=\"COLUMNAS\\nFILAS\"];\n";
        out << "\tnodeMatrix -> " << headerColumns->front()->getNodeName() << ";\n";
        out << "\tnodeMatrix -> " << headerRows->front()->getNodeName() << " [constraint = true];\n";

        /* GRAFICAR CABECERAS CON SUS LISTAS INTERNAS */
        out << headerColumns->graph();
        flush(out);

        /* GRAFICAR FILAS CON SUS LISTAS INTERNAS */
        out << headerRows->graph();
        flush(out);

        /* GRAFICAR RANK DE FILAS */
        Node<TADRow *> *currentRow = headerRows->first();
        while (currentRow != NULL)
        {
            out << "\t{ rank = same; " << currentRow->getNameNode();
            flush(out);
            out << getRankRow(currentRow->getData()->getInternalRow()->first());
            flush(out);
            out << "}\n";
            flush(out);

            currentRow = currentRow->getNext();
        }

        Node<TADColumn *> *currentColumn = headerColumns->first();
        out << "\t{ rank = same; nodeMatrix";
        flush(out);
        while (currentColumn != NULL)
        {
            out << " ; " << currentColumn->getNameNode();
            currentColumn = currentColumn->getNext();
        }
        out << " }\n";

        out << "}";
        flush(out);

        file.close();

        QString compilarDot;
        QTextStream outCompile(&compilarDot);
        outCompile << "dot -Tpng " << filename << ".dot -o " << filename << ".png";
        flush(outCompile);

        qDebug() << compilarDot;
        system(compilarDot.toLatin1().data());
        compilarDot.clear();
    }
}

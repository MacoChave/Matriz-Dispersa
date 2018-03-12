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
    qDebug() << "Limpiando memoria de matriz :)";
    delete headerColumns;
    delete headerRows;
    qDebug() << "Memoria de matriz limpia :D";
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
            qInfo("Se insertó correctamente el nodo :)");
        else
        {
            nodeColumn->getData()->getInternalColumn()->removeOne(value);
            qWarning("No se pudo insertar el nodo en la fila seleccionada :(");
        }
    }
    else
    {
        delete node;
        node = NULL;
        qWarning("No se insertó el nodo :(");
    }
}

void Matrix::erase(int x, int y)
{
    MatrixNode *node = remove(x, y);
    if (node != NULL)
        delete node;

    node = NULL;
}

MatrixNode *Matrix::get(int x, int y)
{
    Node<TADColumn *> *nodeColumn = headerColumns->get(new TADColumn(x));
    MatrixNode *node = NULL;
    if (nodeColumn != NULL)
        node = nodeColumn->getData()->getInternalColumn()->get(new TADMatrixNode(x, y));

    return node;
}

void Matrix::edit(int x, int y, TADMatrixNode *value)
{
    TADColumn *column = new TADColumn(value->getColumnValue());
    TADRow *row = new TADRow(value->getRowValue());
    MatrixNode *node = remove(x, y);

    if (node != NULL)
        return;

    Node<TADColumn *> *nodeColumn = headerColumns->insert(column);
    Node<TADRow *> *nodeRow = headerRows->insert(row);

    node = nodeColumn->getData()->addInternalColumn(value);
    if (nodeRow != NULL)
        nodeRow->getData()->addInternalRow(node);
}

MatrixNode *Matrix::remove(int x, int y)
{
    Node<TADColumn *> *nodeColumn = headerColumns->get(new TADColumn(x));
    Node<TADRow *> *nodeRow = headerRows->get(new TADRow(y));
    MatrixNode *node = NULL;

    if (nodeColumn == NULL || nodeRow == NULL)
        return NULL;

    node = nodeColumn->getData()->getInternalColumn()->get(new TADMatrixNode(x, y));

    if (node == NULL)
        return NULL;

    if (node->getTop() != NULL)
    {
        node->getTop()->setBottom(node->getBottom());

        if (node->getBottom() != NULL)
            node->getBottom()->setTop(node->getTop());
    }
    else
        nodeColumn->getData()->getInternalColumn()->removeFirst();


    if (node->getPreview() != NULL)
    {
        node->getPreview()->setNext(node->getNext());

        if (node->getNext() != NULL)
            node->getNext()->setPreview(node->getPreview());
    }
    else
        nodeRow->getData()->getInternalRow()->removeFirst();


    if (nodeColumn->getData()->getInternalColumn()->isEmpty())
        headerColumns->erase(nodeColumn->getData());

    if (nodeRow->getData()->getInternalRow()->isEmpty())
        headerRows->erase(nodeRow->getData());

    return node;
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
        out << "\tnodeMatrix -> " << headerRows->front()->getNodeName() << ";\n";

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

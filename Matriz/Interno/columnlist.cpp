#include "columnlist.h"

MatrixNode *ColumnList::insert(MatrixNode *current, TADMatrixNode *value)
{
    if (current == NULL)
        return NULL;

    int compare = current->getData()->compareRow(value);

    if (compare == 0)
    {
        delete value;
        value = NULL;
        return current;
    }
    else
    {
        if (compare > 0)
        {
            MatrixNode *temporal = new MatrixNode(value);
            temporal->setBottom(current);
            temporal->setTop(current->getTop());
            current->getTop()->setBottom(temporal);
            current->setTop(temporal);
            count++;

            return temporal;
        }
        else
            return insert(current->getBottom(), value);
    }
}

MatrixNode *ColumnList::get(MatrixNode *current, TADMatrixNode *value)
{
    if (current != NULL)
        return NULL;

    int compare = current->getData()->compareColumn(value);

    if (compare == 0)
    {
        /* COMPARAR NIVELES */
        return current;
    }
    else
    {
        if (compare < 0)
            return insert(current->getBottom(), value);

        return NULL;
    }
}

ColumnList::ColumnList()
{
    count = 0;
    head = NULL;
    tail = NULL;
}

ColumnList::~ColumnList()
{
    clear();
}

bool ColumnList::isEmpty()
{
    return (head == NULL);
}

int ColumnList::size()
{
    return count;
}

void ColumnList::clear()
{
    while (!isEmpty())
        removeFirst();
}

MatrixNode *ColumnList::push_front(TADMatrixNode *value)
{
    MatrixNode *node = new MatrixNode(value);

    if (isEmpty())
        head = tail = node;
    else
    {
        node->setBottom(head);
        head->setTop(node);
        head = node;
    }

    count++;

    return node;
}

MatrixNode *ColumnList::push_back(TADMatrixNode *value)
{
    MatrixNode *node = new MatrixNode(value);

    if (isEmpty())
        head = tail = node;
    else
    {
        node->setTop(tail);
        tail->setBottom(node);
        tail = node;
    }

    count++;

    return node;
}

MatrixNode *ColumnList::insert(TADMatrixNode *value)
{
    if (isEmpty())
    {
        MatrixNode *temporal = new MatrixNode(value);
        head = tail = temporal;
        count++;

        return temporal;
    }
    else
    {
        if (head->getData()->compareRow(value) > 0)
            return push_front(value);
        else if (tail->getData()->compareRow(value) < 0)
            return push_back(value);
        else
            return insert(head, value);
    }
}

MatrixNode *ColumnList::removeFirst()
{
    if (isEmpty())
        return NULL;

    MatrixNode *temporal = head;
    head = temporal->getBottom();
    if (size() > 1)
        head->setTop(NULL);
    else
        tail = head;
    count--;

    return temporal;
}

MatrixNode *ColumnList::removeLast()
{
    if (isEmpty())
        return NULL;

    MatrixNode *temporal = tail;
    tail = temporal->getTop();
    if (size() > 1)
        tail->setBottom(NULL);
    else
        head = tail;
    count--;

    return temporal;
}

MatrixNode *ColumnList::removeOne(TADMatrixNode *value)
{
    if (head->getData()->compareColumn(value) == 0)
        return removeFirst();
    if (tail->getData()->compareColumn(value) == 0)
        return removeLast();

    if (head->getData()->compareColumn(value) < 0
            && tail->getData()->compareColumn(value) > 0)
    {
        MatrixNode *temporal = get(head->getBottom(), value);

        if (temporal->getBottom() != NULL)
            temporal->getBottom()->setTop(temporal->getTop());
        if (temporal->getTop() != NULL)
            temporal->getTop()->setBottom(temporal->getBottom());

        temporal->setBottom(NULL);
        temporal->setTop(NULL);
        count--;

        return temporal;
    }
    else
        return NULL;
}

MatrixNode *ColumnList::first()
{
    return head;
}

MatrixNode *ColumnList::last()
{
    return tail;
}

TADMatrixNode *ColumnList::front()
{
    return head->getData();
}

TADMatrixNode *ColumnList::back()
{
    return tail->getData();
}

MatrixNode *ColumnList::get(TADMatrixNode *value)
{
    if (isEmpty())
        return NULL;

    if (head->getData()->compareColumn(value) == 0)
        return head;
    if (tail->getData()->compareColumn(value) == 0)
        return tail;

    if (head->getData()->compareColumn(value) < 0
            && tail->getData()->compareColumn(value) > 0)
        return get(head->getBottom(), value);
    else
        return NULL;
}

QString ColumnList::graph()
{
    QString listGraph;

    MatrixNode *temporal = head;
    while (temporal != NULL)
    {
        listGraph.append(temporal->createNode());
        listGraph.append(temporal->pointNode(temporal->VERTICAL));

        temporal = temporal->getBottom();
    }

    return listGraph;
}

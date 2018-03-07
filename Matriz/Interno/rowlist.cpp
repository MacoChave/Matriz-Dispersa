#include "rowlist.h"

MatrixNode *RowList::insert(MatrixNode *current, TADMatrixNode *value)
{
    if (current != NULL)
        return NULL;

    int compare = current->getData()->compareRow(value);

    if (compare == 0)
        return current;
    else
    {
        if (compare > 0)
        {
            MatrixNode *temporal = new MatrixNode(value);
            temporal->setNext(current);
            temporal->setPreview(current->getPreview());
            current->getPreview()->setNext(temporal);
            current->setPreview(temporal);
            count++;

            return temporal;
        }
        else
            return insert(current->getNext(), value);
    }
}

MatrixNode *RowList::get(MatrixNode *current, TADMatrixNode *value)
{
    if (current == NULL)
        return NULL;

    int compare = current->getData()->compareRow(value);

    if (compare == 0)
        return current;
    else
    {
        if (compare < 0)
            return get(current->getNext(), value);
        else
            return NULL;
    }
}

RowList::RowList()
{
    count = 0;
    head = NULL;
    tail = NULL;
}

RowList::~RowList()
{
    clear();
}

bool RowList::isEmpty()
{
    return head == NULL;
}

int RowList::size()
{
    return count;
}

void RowList::clear()
{
}

MatrixNode *RowList::push_front(TADMatrixNode *value)
{
    MatrixNode *node = new MatrixNode(value);

    if (isEmpty())
        head = tail = node;
    else
    {
        node->setNext(head);
        head->setPreview(node);
        head = node;
    }

    count++;

    return node;
}

MatrixNode *RowList::push_back(TADMatrixNode *value)
{
    MatrixNode *node = new MatrixNode(value);

    if (isEmpty())
        head = tail = node;
    else
    {
        node->setPreview(tail);
        tail->setNext(node);
        tail = node;
    }

    count++;

    return node;
}

MatrixNode *RowList::insert(TADMatrixNode *value)
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

MatrixNode *RowList::removeFirst()
{
    if (isEmpty())
        return NULL;

    MatrixNode *temporal = head;
    head = temporal->getNext();
    if (size() > 1)
        head->setPreview(NULL);
    else
        tail = head;
    count--;

    return temporal;
}

MatrixNode *RowList::removeLast()
{
    if (isEmpty())
        return NULL;

    MatrixNode *temporal = tail;
    tail = temporal->getPreview();
    if (size() > 1)
        tail->setNext(NULL);
    else
        head = tail;
    count--;

    return temporal;
}

MatrixNode *RowList::removeOne(TADMatrixNode *value)
{
    if (head->getData()->compareRow(value) == 0)
        return removeFirst();
    if (tail->getData()->compareRow(value) == 0)
        return removeLast();

    if (head->getData()->compareRow(value) < 0
            && tail->getData()->compareRow(value) > 0)
    {
        MatrixNode *temporal = get(head->getNext(), value);

        if (temporal->getNext() != NULL)
            temporal->getNext()->setPreview(temporal->getPreview());
        if (temporal->getPreview() != NULL)
            temporal->getPreview()->setNext(temporal->getNext());

        temporal->setNext(NULL);
        temporal->setPreview(NULL);
        count--;

        return temporal;
    }
    else
        return NULL;
}

MatrixNode *RowList::fist()
{
    return head;
}

MatrixNode *RowList::last()
{
    return tail;
}

TADMatrixNode *RowList::front()
{
    return head->getData();
}

TADMatrixNode *RowList::back()
{
    return tail->getData();
}

MatrixNode *RowList::get(TADMatrixNode *value)
{
    if (isEmpty())
            return NULL;

        if (head->getData()->compareRow(value) == 0)
            return head;
        if (tail->getData()->compareRow(value) == 0)
            return tail;

        if (head->getData()->compareRow(value) < 0
                && tail->getData()->compareRow(value) > 0)
            return get(head->getNext(), value);
        else
            return NULL;
}

void RowList::graph(QString filename)
{

}

#include "glthreads.h"

template <typename T>
T *Node<T>::getLeft() { return this->left; }

template <typename T>
T *Node<T>::getRight() { return this->right; }

template <typename T>
void Node<T>::setLeft(T *left) { this->left = left; }

template <typename T>
void Node<T>::setRight(T *right) { this->right = right; }

template <typename T>
void Node<T>::init()
{
    this->left = nullptr;
    this->right = nullptr;
}

template <typename T>
void Node<T>::addNext(T *currNode, T *newNode)
{
    if (!currNode->right)
    {
        currNode->right = newNode;
        newNode->left = currNode;
        return;
    }

    T *temp = currNode->right;
    currNode->right = newNode;
    newNode->left = currNode;
    newNode->right = temp;
    temp->left = newNode;

    return;
}

template <typename T>
void glthread<T>::addNode(T *node)
{
    node->setLeft(nullptr);
    node->setRight(nullptr);
    if (!this->head)
    {
        this->head = node;
        return;
    }
    T *head = this->head;
    Node<T>::addNext(node, head);
    this->head = node;
}

template <typename T>
void Node<T>::removeNode(T *node)
{
    if (!node->left)
    {
        if (node->right)
        {
            node->right->left = nullptr;
            node->right = nullptr;
            return;
        }

        return;
    }

    if (!node->right)
    {
        node->left->right = nullptr;
        node->left = nullptr;
        return;
    }

    node->left->right = node->right;
    node->right->left = node->left;
    node->left = nullptr;
    node->right = nullptr;
    delete node;
}

template<typename T>
void glthread<T>::removeNode(T *node)
{
    T *head = this->head;

    if (head == node)
    {
        T *temp = head->getRight();
        delete head;
        this->head = temp;
    }

    Node<T>::removeNode(node);
}

template <typename T>
void glthread<T>::initThread(unsigned int offset)
{
    this->head = nullptr;
    this->offset = offset;
}


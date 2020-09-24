#ifndef _AVL_H_
#define _AVL_H_

#include <algorithm>

namespace Avl
{
    template <typename T>
    struct Node
    {
        Node() = default;

        Node(T k) : key(k), height(0), left(nullptr), right(nullptr)
        {
        }

        T key;
        long height;
        Node *left;
        Node *right;
    };

    template <typename T>
    long altura(Node<T> *&root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return root->height;
        }
    }

    long max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }

    template <typename T>
    void rotateRight(Node<T> *&root)
    {
        Node<T> *temporal = root->left;
        Node<T> *temporal2 = root->right;

        //hacer la rotacion...
        temporal->right = root;
        root->left = temporal2;

        //los hijos pueden ser null

        root->height = max(altura(root->left), altura(root->right)) + 1;
        temporal->height = max(altura(temporal->left), altura(temporal->right)) + 1;
    
        root = temporal;
    }

    template <typename T>
    void rotateLeft(Node<T> *&root)
    {
        Node<T> *temp = root->right;
        Node<T> *temp2 = temp->left;

        //hacer la rotacion...
        temp->left = root;
        root->right = temp2;

        //los hijos pueden ser NULL

            root->height = max(altura(root->left), altura(root->right)) + 1;
            temp->height = max(altura(temp->left), altura(temp->right)) + 1;

        root = temp2;
    }

} // namespace Avl

#endif

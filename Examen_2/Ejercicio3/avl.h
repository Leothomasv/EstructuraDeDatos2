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
        Node<T> *temporal = root->right;
        root->right = temporal->left;
        temporal->left = root;

        //los hijos pueden ser nul
       
            root->height = max(altura(root->left), altura(root->right)) + 1;
            temporal->height = max(altura(temporal->left), altura(temporal->right)) + 1;

        root = temporal;
    }
    // root->height = max(root->right->height, root->left->height) + 1;
    //temp->height = max(temp->right->height, temp->left->height) + 1;

    template <typename T>
    void rotateLeft(Node<T> *&root)
    {
        Node<T> *temp = root->left;
        root->left = temp->right;
        temp->right = root;

        //los hijos pueden ser NULL
        if (root->right != nullptr && root->left != nullptr)
        {
            root->height = max(altura(root->left), altura(root->right)) + 1;
            temp->height = max(altura(temp->left), altura(temp->right)) + 1;
        }

        root = temp;
    }

} // namespace Avl

#endif

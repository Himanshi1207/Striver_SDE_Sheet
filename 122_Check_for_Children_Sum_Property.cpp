#include <bits/stdc++.h>
using namespace std;
struct T
{
    int val;
    T *left;
    T *right;
    T() : val(0), left(nullptr), right(nullptr) {}
    T(int x) : val(x), left(nullptr), right(nullptr) {}
    T(int x, T *left, T *right) : val(x), left(left), right(right) {}
};

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int f(BinaryTreeNode<int> *root)
{

    if (root->left == NULL && root->right == NULL)

        return root->data;

    int parent = root->data;

    int children = 0;

    if (root->left)

        children += root->left->data;

    if (root->right)

        children += root->right->data;

    if (parent > children)
    {

        int l = 0, r = 0;

        if (root->left)
        {

            root->left->data = parent;

            l = root->left->data = f(root->left);
        }

        if (root->right)
        {

            root->right->data = parent;

            r = root->right->data = f(root->right);
        }

        children = l + r;

        return children;
    }
    else
    {

        int l = 0, r = 0;

        root->data = children;

        if (root->left)

            l = root->left->data = f(root->left);

        if (root->right)

            r = root->right->data = f(root->right);

        children = l + r;

        return children;
    }
}

void changeTree(BinaryTreeNode<int> *root)
{

    if (root)

        root->data = f(root);
}
#include <bits/stdc++.h>
template <typename T>
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

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

void solve(BinaryTreeNode<int> *root, int X, int &ceil, int &tmp)
{

    if (!root)
        return;

    if (root->data == X)
    {

        ceil = root->data;

        return;
    }

    if (root->data > X)
    {

        if (root->data < tmp)
        {

            tmp = root->data;

            ceil = root->data;
        }

        solve(root->left, X, ceil, tmp);
    }
    else

        solve(root->right, X, ceil, tmp);
}

int findCeil(BinaryTreeNode<int> *root, int X)
{

    if (!root)
        return 0;

    int ceil = -1, tmp = INT_MAX;

    solve(root, X, ceil, tmp);

    return ceil;
}
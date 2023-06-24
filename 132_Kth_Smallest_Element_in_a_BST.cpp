#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void inordertra(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        inordertra(root->left, inorder);
        inorder.push_back(root->val);
        inordertra(root->right, inorder);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> inorder;
        inordertra(root, inorder);
        return inorder[--k];
    }
};
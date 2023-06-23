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
    TreeNode *construct(vector<int> &preorder, int ps, int pe)
    {
        if (ps > pe)
            return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
        int i = ps + 1;
        for (; i <= pe; i++)
        {
            if (preorder[ps] < preorder[i])
                break;
        }
        root->left = construct(preorder, ps + 1, i - 1);
        root->right = construct(preorder, i, pe);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return construct(preorder, 0, preorder.size() - 1);
    }
};
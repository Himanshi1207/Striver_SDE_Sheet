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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size())
            return NULL;
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return buildtreepostin(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
    }
    TreeNode *buildtreepostin(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &mp)
    {
        if (ps > pe or is > ie)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pe]);
        int inroot = mp[root->val];
        int numsleft = inroot - is;
        root->left = buildtreepostin(inorder, is, inroot - 1, postorder, ps, ps + numsleft - 1, mp);
        root->right = buildtreepostin(inorder, inroot + 1, ie, postorder, ps + numsleft, pe - 1, mp);
        return root;
    }
};
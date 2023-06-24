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
    bool inorder(TreeNode *root, map<int, int> &mp, int k)
    {
        if (!root)
            return false;
        if (mp.find(k - root->val) != mp.end())
            return true;
        mp[root->val]++;

        return inorder(root->left, mp, k) or inorder(root->right, mp, k);
    }
    bool findTarget(TreeNode *root, int k)
    {
        map<int, int> mp;
        return inorder(root, mp, k);
    }
};
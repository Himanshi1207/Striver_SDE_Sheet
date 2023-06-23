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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *ans = root;
        while (ans != NULL)
        {
            if (ans->val == val)
                return ans;
            else if (ans->val < val)
            {
                ans = ans->right;
            }
            else
                ans = ans->left;
        }
        return ans;
    }
};
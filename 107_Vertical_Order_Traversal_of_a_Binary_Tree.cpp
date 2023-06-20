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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty())
        {
            auto temp = todo.front();
            todo.pop();
            TreeNode *t = temp.first;
            int x = temp.second.first, y = temp.second.second;
            nodes[x][y].insert(t->val);
            if (t->left)
            {
                todo.push({t->left, {x - 1, y + 1}});
            }
            if (t->right)
            {
                todo.push({t->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto it : p.second)
            {
                col.insert(col.end(), it.second.begin(), it.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
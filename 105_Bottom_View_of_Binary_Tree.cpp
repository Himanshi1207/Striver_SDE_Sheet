#include <bits/stdc++.h>
using namespace std;
// Function to return a list containing the bottom view of the given tree.
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        if (!root)
            return {};
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            Node *temp = q.front().first;
            int h = q.front().second;
            q.pop();
            mp[h] = temp->data;
            if (temp->left)
                q.push({temp->left, h - 1});
            if (temp->right)
                q.push({temp->right, h + 1});
        }
        for (auto it : mp)
            ans.push_back(it.second);
        return ans;
    }
};
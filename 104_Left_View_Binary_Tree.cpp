#include <bits/stdc++.h>
using namespace std;

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
vector<int> leftView(Node *root)
{
    if (root == NULL)
        return {};
    // Your code here
    queue<Node *> q;
    vector<int> ans;

    q.push(root);
    while (!q.empty())
    {
        //   Node* front=q.front();
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Node *front = q.front();
            q.pop();
            if (i == 0)
            {
                ans.push_back(front->data);
            }
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }

    return ans;
}
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    int ans;
    void reverseinorder(Node *root, int &k)
    {
        if (root == NULL)
            return;
        reverseinorder(root->right, k);
        if (--k == 0)
        {
            ans = root->data;
            return;
        }
        reverseinorder(root->left, k);
    }
    int kthLargest(Node *root, int K)
    {
        // Your code here
        reverseinorder(root, K);
        return ans;
    }
};
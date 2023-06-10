// ṬC-O(N)
// SC-O(1)
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *iter = head, *front = head;
        //         step1: adding dummy nodes in between the original nodes
        while (iter != NULL)
        {
            front = iter->next;
            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        //         points the random pointer to the deep copy nodes
        iter = head;
        while (iter != NULL)
        {
            if (iter->random != NULL)
            {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        iter = head;
        Node *dummy = new Node(0);
        Node *copy = dummy;
        while (iter != NULL)
        {
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = iter->next;
        }
        return dummy->next;
    }
};
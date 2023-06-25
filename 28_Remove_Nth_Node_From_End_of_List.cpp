#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = new ListNode(0, head);
        ListNode *start = temp;
        ListNode *end = head;
        // n=n-1;
        while (n--)
        {
            end = end->next;
        }
        while (end != NULL)
        {
            start = start->next;
            end = end->next;
        }
        start->next = start->next->next;
        return temp->next;
    }
};
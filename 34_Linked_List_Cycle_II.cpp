// TC-O(n)
// SC-O(1)
#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head, *fast=head;
        ListNode* entry=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                while(entry and slow){
                    if(entry==slow)
                        return slow;
                    else{
                        entry=entry->next;
                        slow=slow->next;
                    }
                }
            }
        }
        return NULL;
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy= new ListNode();
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        for(int i=0;i<n;i++)
        fast=fast->next;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
    
        }
        slow->next=slow->next->next;
        return dummy->next;
    }
};
//TC:O(N);
//SC:O(1);
//Problem:https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

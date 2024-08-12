class Solution {
public:
    void reorderList(ListNode* head) {
        //edge-case
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        return;
        //find-middle-element
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //Reverse-Second-Half
        ListNode* prev=NULL;
        ListNode* curr=slow;
        ListNode* nxt;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
       
        //merge
        ListNode* first=head;
        ListNode* second=prev;
        while(second->next)
        {
            ListNode* temp1= first->next;
            ListNode* temp2= second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
        return;
    }
};

//TC:O(N)
//SC:O(1)
//Problem:https://leetcode.com/problems/reorder-list/description/

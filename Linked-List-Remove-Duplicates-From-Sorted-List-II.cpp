class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp= new ListNode(-1);
        temp->next=head;
        ListNode* curr=temp;
   
        while(curr->next && curr->next->next)
        {
            int z= curr->next->val;
            if(curr->next->val==curr->next->next->val)
            {
              while(curr->next && curr->next->val==z)
              curr->next=curr->next->next;  
            }
            else
            curr=curr->next;
        }
        return temp->next;;
    }
};
//TC:O(N)
//SC:O(1)
//Problem:https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

//-------------------ITERATIVE-SOLUTION---------------
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *nxt;
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
};

//TC=O(N)
//SC=O(1)


//----------RECURSIVE-SOLUTION-------------------

Node* reverseLinkedList(Node *head)
{
       if(head==NULL||head->next==NULL)
       return head;

       Node* newHead= reverseLinkedList(head->next);
       Node* front= head->next;
       front->next=head;
       head->next=NULL;
       return newHead;
}

//TC=O(N)
//SC=O(N)[For recursive call stack]

//Problem:https://leetcode.com/problems/reverse-linked-list/description/

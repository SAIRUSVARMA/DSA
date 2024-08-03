//---------------------------------ITERATIVE---------------------------------
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val > l2->val)
        swap(l1,l2);
        ListNode* res=l1;
        while(l1&&l2)
        {
             ListNode* temp=NULL;
             while(l1 && (l1->val<=l2->val))
             {
                temp=l1;
                l1=l1->next;
             }
             temp->next=l2;
             swap(l1,l2);
        }
       return res;
    }
};

//TC:O(N1+N2)[N1 AND N2 ARE SIZE OF GIVEN LINKED LISTS]
//SC:O(1)

//---------------------------------RECURSIVE---------------------------------
class Solution {
public:
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //base-case
       if (!l1) return l2;
       if (!l2) return l1;

   //recursive-case
    if (l1->val < l2->val)
       {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
       }
    else 
      {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
      }

    }
};

//TC:O(N1+N2)[N1 AND N2 ARE SIZE OF GIVEN LINKED LISTS]
//SC:O(N1+N2)[FOR RECURSIVE CALL STACK]
//Problem:https://leetcode.com/problems/merge-two-sorted-lists/

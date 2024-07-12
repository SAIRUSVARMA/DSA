//----------------------2 POINTERS(OPTIMAL)----------------------------------
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head==NULL||head->next==NULL)
        return false;

        ListNode* fast=head;
        ListNode* slow=head;

        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            return true;
        }
         
         return false;
         
    }
};

//TC:O(N)
//SC:O(1)

//------------------------------HASHING(BRUTE-FORCE)--------------------------
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> visited_nodes;
        ListNode *current_node = head;
        while (current_node != nullptr) {
            if (visited_nodes.find(current_node) != visited_nodes.end()) {
                return true;
            }
            visited_nodes.insert(current_node);
            current_node = current_node->next;
        }
        return false;
    }
};

//TC:O(N)
//SC:O(N)[For Hashing]

//Problem:https://leetcode.com/problems/linked-list-cycle/description/

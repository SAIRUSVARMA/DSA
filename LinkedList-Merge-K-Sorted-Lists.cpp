struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
       priority_queue<ListNode*, vector<ListNode*>, compare>minHeap;
        
        for(ListNode* i:lists)
        {
            if(i)
            minHeap.push(i);
        }

        ListNode dummy(0);
        ListNode* curr= &dummy;

        while(!minHeap.empty())
        {
            ListNode* top=minHeap.top();
            minHeap.pop();

            curr->next=top;
            curr=curr->next;

            if(top->next)
            minHeap.push(top->next);
        }
      return dummy.next;
    }
};

//TC: O(NlogK)[it's approximately O[N^2 log N ] because let's say each list has n nodes, which span over n lists, 
               so total nodes will be n*n, but here total nodes are denoted by N]

### Time Complexity Analysis

#### Time Complexity of Merging K Sorted Linked Lists Using Min-Heap

1. **Inserting All Nodes into the Min-Heap:**
   - **Operation:** Inserting each node from K linked lists into the min-heap.
   - **Cost per Node:** O(log K) (insertion into a min-heap).
   - **Total Cost:** If there are N total nodes across all K linked lists, the total cost for inserting all nodes into the min-heap is O(N log K).

2. **Extracting Nodes from the Min-Heap:**
   - **Operation:** Extracting the minimum node from the min-heap and appending it to the merged list.
   - **Cost per Extraction:** O(log K) (extraction from a min-heap).
   - **Total Cost:** Since we perform this operation N times (once for each node), the total cost for extracting all nodes from the min-heap is O(N log K).

3. **Total Time Complexity:**
   - The total time complexity of the algorithm is the sum of the costs for inserting and extracting nodes.
   - **Total Time Complexity:** O(N log K).

//SC: O(K)[The space complexity is mainly due to the min-heap, which at most contains K nodes at any time.]
//Problem:https://leetcode.com/problems/merge-k-sorted-lists/

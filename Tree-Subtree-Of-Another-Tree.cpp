class Solution {
public:

    bool isSametree(TreeNode* r, TreeNode* s)
    {
        if(!r && !s) return true;
        if(!r || !s) return false;
        return r->val==s->val && isSametree(r->left,s->left) && isSametree(r->right,s->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSametree(root,subRoot))
        return true;
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
}; 

/*TC:O(M*N)+O(M) i.e O(M*N)
### Key Points
- **Time Complexity**: O(N × M)
  - **Reason**: 
    - You might need to compare `subRoot` to a subtree at every node of `root`.
    - Each comparison can take up to O(M) time, where m is the number of nodes in `subRoot`.
*/
//SC:O(H)[Height of the tree](due to recursion stack)
//Problem:https://leetcode.com/problems/subtree-of-another-tree/

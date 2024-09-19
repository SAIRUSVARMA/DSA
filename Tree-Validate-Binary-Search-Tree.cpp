class Solution {
public:
    bool validateBST(TreeNode* root, long min, long max )
    {
        if(!root)
        return true;
        if(root->val<=min||root->val>=max)
        return false;
        return validateBST(root->left, min, root->val ) && validateBST(root->right, root->val, max );
    }
    
    bool isValidBST(TreeNode* root) {
        return validateBST(root,LONG_MIN,LONG_MAX);
    }
};


//TC:O(N)[each node is visited once]
/*SC:O(H)[h is the height of the tree, due to the recursive function call stack. 
           For a balanced tree, h = log(n), and for a skewed tree, h = n]*/
//Problem:https://leetcode.com/problems/validate-binary-search-tree/

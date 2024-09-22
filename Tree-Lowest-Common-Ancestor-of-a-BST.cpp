class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base-case
        if(root==NULL|| p==root || q==root)
        return root;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left==NULL)
        return right;
        else if(right==NULL)
        return left;
        else
        return root;
    }
};

//TC:O(N)
//SC:O(N)[or O(H)]
//Problem:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

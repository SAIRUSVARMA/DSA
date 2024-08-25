class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
        return 0;
        return max( maxDepth(root->left), maxDepth(root->right) ) + 1;
    }
};
//TC:O(N)
/*SC:O(H)[ The space complexity is determined by the maximum depth of the recursion stack,
           which is equal to the height of the binary tree. In the worst case (e.g., if the tree is skewed),
           the space complexity is O(N), but in the best case (a perfectly balanced tree), it is O(log N).
           Here H is the height of the tree.]*/
//Problem:https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

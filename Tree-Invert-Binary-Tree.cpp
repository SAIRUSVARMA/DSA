class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        return root;

        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;

    }
};

//TC:O(N)
//SC:O(H)[H is the height of tree]
//Problem:https://leetcode.com/problems/invert-binary-tree/

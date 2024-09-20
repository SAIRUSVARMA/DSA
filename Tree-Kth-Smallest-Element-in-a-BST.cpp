class Solution {
public:
  int ans;
    void inorder(TreeNode* root, int& k)
    {
        if(!root) return;
        inorder(root->left,k);
        if(--k==0) ans=root->val;
         inorder(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }

    //private:
    //int ans;[you can use private if you want]
};
//TC:O(N)
//SC:O(H)[O(logN) best case : Balanced BST, O(N) worst case: skewed BST]
//Problem:https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

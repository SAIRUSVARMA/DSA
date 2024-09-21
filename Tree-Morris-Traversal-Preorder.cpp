class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        if(!root)
        return preorder;
        TreeNode* curr=root;
        while(curr)
        {
            //case-1
            if(curr->left==NULL)
            {
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            //case-2
            else
            {
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                   prev->right=curr;
                   preorder.push_back(curr->val);
                   curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};
//TC:O(N)
//SC:O(1)
//Problem:https://leetcode.com/problems/binary-tree-preorder-traversal/

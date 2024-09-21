class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        if(!root)
        return inorder;
        TreeNode* curr=root;
        while(curr)
        {
            //case-1
            if(curr->left==NULL)
            {
                inorder.push_back(curr->val);
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
                  curr=curr->left;
              }
              else
              {
                  prev->right=NULL;
                  inorder.push_back(curr->val);
                  curr=curr->right;
              }
            }
        }
        return inorder;
    }
};

TC:O(N)
SC:O(1)
Problem:https://leetcode.com/problems/binary-tree-inorder-traversal/  

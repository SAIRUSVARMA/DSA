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
----------------------------------------------------------------------------------MORRIS-TRAVERSAL--------------------------
class Solution {
public:

    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int count=0;
        TreeNode* curr=root;
        while(curr)
        {
            //case-1
            if(curr->left==NULL)
            {
                count++;
                if(count==k)
                ans=curr->val;
                curr=curr->right;
            }
            else
            {
                TreeNode* prev = curr->left;
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
                    count++;
                    if(count==k)
                    ans=curr->val;
                    curr=curr->right;
                }

                
            }
        }
        return ans;
    }

   
};  
//TC:O(N)
//SC:O(1)
//Problem:https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

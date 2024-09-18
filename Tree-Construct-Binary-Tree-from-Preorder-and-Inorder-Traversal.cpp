class Solution {
public:
   TreeNode* helper(vector<int> inorder, vector<int> preorder, int prestart, int instart, int inend)
   {
     if(prestart>=preorder.size()||instart>inend)
     return NULL;
     TreeNode* root=new TreeNode(preorder[prestart]);
     int inindex=0;
     for(int i=0;i<inorder.size();i++)
     {
        if(inorder[i]==root->val)
        inindex=i;
     }
     root->left=helper(inorder,preorder,prestart+1,instart,inindex-1);
     root->right=helper(inorder,preorder,prestart+(inindex-instart+1),inindex+1,inend);
     return root;

   }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preorder:root->left->right
        //inorder:left->root->right
        //postorder:left->right->root
        return helper(inorder,preorder,0,0,inorder.size()-1);
    }
};
//......................................TC-and-SC-Analysis..........................................................
//TC:O(N^2)
/* O(N^2) in the worst case, where N is the number of nodes in the tree.
This happens because, for every recursive call,
we scan the entire inorder list to find the index of the root,
which is an O(N) operation.*/

//SC:O(N)
/*O(N) due to the recursion stack, which in the worst case (skewed tree),
will go as deep as the number of nodes.*/

//Problem:https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

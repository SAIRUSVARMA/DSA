class Solution {
public:

 int maxSum;

    int solve(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        int l=solve(root->left);
        int r=solve(root->right);

        int case_1 = l+r+root->val; //neeche hi mil gaya ans
        int case_2 = max(l,r)+root->val;//koi ek accha hai l/r mein
        int case_3 = root->val;//sirf root hi accha hein;

        maxSum=max({maxSum, case_1 , case_2 , case_3});
        return max(case_2,case_3);
        // in case_1 we already found the path and the ans, we already used both sub trees so can't be used further in recursion.
        // so we only send from case_2 or case_3

    }

    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};

//TC:O(N)
//SC:O(H)[H is the height of the tree]
//Problem:https://leetcode.com/problems/binary-tree-maximum-path-sum/

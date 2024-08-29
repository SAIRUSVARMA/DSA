class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(!root)
        return v;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
                level.push_back(temp->val);
            }
            v.push_back(level);
        }
        return v;
    }
};

//TC:O(N)[We are iterating through all the nodes]
//SC:O(N)[We are storing all the nodes in the queue]
//Problem:https://leetcode.com/problems/binary-tree-level-order-traversal/

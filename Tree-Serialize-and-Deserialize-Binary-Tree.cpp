class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL)
            s.append("#,");
            else
            s.append(to_string(curr->val)+',');
            if(curr)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        TreeNode * root=new TreeNode(stoi(str));
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            getline(ss,str,',');
            if(str=="#")
            curr->left=NULL;
            else
            {
                TreeNode* LeftNode=new TreeNode(stoi(str));
                curr->left=LeftNode;
                q.push(curr->left);
            }
            getline(ss,str,',');
            if(str=="#")
            curr->right=NULL;
            else
            {
                TreeNode* RightNode=new TreeNode(stoi(str));
                curr->right=RightNode;
                q.push(curr->right);
            }
        }
      return root;
    }
};

//TC:O(N)
//SC:O(N)(We use string of 2*N size because we have ',' after each node, but still its all order of N)
//Problem:https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

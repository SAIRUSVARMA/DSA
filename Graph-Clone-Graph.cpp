class Solution {
public:
    
    Node* dfs(Node* curr, map<Node*, Node*>& mp)
    { vector<Node*>neighbour;
      Node * clone=new Node(curr->val);
      mp[curr]=clone;

      for(auto it:curr->neighbors)
      {
        if(mp.find(it)!=mp.end())
        {
            neighbour.push_back(mp[it]);
        }
        else
        {
           neighbour.push_back(dfs(it,mp));
        }
      }
      
      clone->neighbors=neighbour;
      return clone;

    }
    
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>mp;
        if(node==NULL)
        return NULL;
        if(node->neighbors.size()==0)
        {
            Node* clone=new Node(node->val);
            return clone;
        }
        return dfs(node,mp);
    }
};

//TC:O(V+E)[where V is the number of vertices (nodes) and E is the number of edges.]
//SC:O(V)[ due to the hashmap storing cloned nodes and the recursion stack in the worst case(fully connected graph)].
//Problem:https://leetcode.com/problems/clone-graph/

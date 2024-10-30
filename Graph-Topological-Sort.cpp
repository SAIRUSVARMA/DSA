
class Solution {
  public:
    
   void dfs(int node, int visited[], stack<int>&st, vector<vector<int>>& adj )
    {
        visited[node]=1;
        vector<int>temp=adj[node];
        
        for(auto it:temp)
        {
            if(!visited[it])
            dfs(it,visited,st,adj);
        }
        
        st.push(node);
    }
    
    vector<int> topologicalSort(vector<vector<int>>& adj)
    {
        int v=adj.size();
        int visited[v]={0};
        stack<int>st;
        
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,st,adj);
            }
        }
        
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

//TC:O(V+E)[in dfs we go through all nodes i.e v, and in adj list we go through all edges, so total V+E]
//SC:O(V)[For Stack and array]
//Problem:https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        if(heights.size()<1)
        return ans;

        vector<vector<int>>pacific(heights.size(), vector<int>(heights[0].size(),0));
        vector<vector<int>>atlantic(heights.size(), vector<int>(heights[0].size(),0));

        for(int col=0; col<heights[0].size(); col++)
        {
            dfs(heights,0,col,INT_MIN,pacific);
            dfs(heights,heights.size()-1,col,INT_MIN,atlantic);
        }

        for(int row=0; row<heights.size(); row++)
        {
            dfs(heights,row,0,INT_MIN,pacific);
            dfs(heights,row,heights[0].size()-1,INT_MIN,atlantic);
        }

        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                if(pacific[i][j]==1 && atlantic[i][j]==1)
                {
                    vector<int>v(2);
                    v[0]=i;
                    v[1]=j;
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, int i, int j, int prev,vector<vector<int>>& ocean)
    {
        if(i<0||j<0||i>=heights.size()||j>=heights[0].size())
        return;

        if(ocean[i][j]==1)
        return;

        if(heights[i][j]<prev)
        return;

        ocean[i][j]=1;

        dfs(heights,i+1,j,heights[i][j],ocean);
        dfs(heights,i-1,j,heights[i][j],ocean);
        dfs(heights,i,j+1,heights[i][j],ocean);
        dfs(heights,i,j-1,heights[i][j],ocean);

    }
};

//TC:O(N^2) or O(M*N) [Each cell is visited at most twice (once for each ocean).]
//SC:O(M*N) [for the visited matrices and call stack].
//Problem:https://leetcode.com/problems/pacific-atlantic-water-flow/

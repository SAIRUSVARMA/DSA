class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }

        return count;
    }
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size())
        return;

        if(grid[i][j]=='0')
        return;

        grid[i][j]='0'; //(If grid[i][j]=='1', we change it to '0')

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
};

//TC:O(N^2) or O(M*N) every cell is visited once.
//SC:O(N^2) OR O(M*N) in the worst case for the recursion stack (if the grid is entirely land(1's)).
//Problem:https://leetcode.com/problems/number-of-islands/

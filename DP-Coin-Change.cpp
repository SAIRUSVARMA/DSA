class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m=coins.size()+1;
        int n=amount+1;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=1;i<n;i++)
        {
            dp[0][i]=INT_MAX-1;
        }

        for(int i=1;i<m;i++)
        {
           for(int j=1;j<n;j++)
           {
             if(coins[i-1]>j)
             dp[i][j]=dp[i-1][j];
             else
             dp[i][j]=min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);

           }
        }
        if(dp[m-1][n-1]>10000)
        return -1;
        else
        return dp[m-1][n-1];
    }
};
//TC:O(M*N)
//SC:O(M*N)
//Problem:https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int m=nums.size();
        int n=target+1;
        vector<unsigned int>dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i>=nums[j])
                {
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};

//TC:O(M*N)
//SC:O(N)
//Problem:https://leetcode.com/problems/combination-sum-iv/

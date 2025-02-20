class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                dp[i]=max(dp[i], 1+dp[j]);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
//TC:O(N^2)
//SC:O(N)
//Problem:https://leetcode.com/problems/longest-increasing-subsequence/

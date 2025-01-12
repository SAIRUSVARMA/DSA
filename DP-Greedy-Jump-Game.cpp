class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>maxReach)
            return false;
            maxReach=max(maxReach, i+nums[i]);
        }
        return true;
    }
};
//Greedy Algorithm
//TC:O(N)
//SC:O(1)
//.....................................................................................................................
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;

        for (int i = 0; i < nums.size(); i++) 
        {
            if (!dp[i]) continue;
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) 
            {
                dp[i + j] = true;
            }
        }

        return dp.back();
    }
};

//DP
//TC:O(N^2)
//SC:O(N)
//Problem:https://leetcode.com/problems/jump-game/description/


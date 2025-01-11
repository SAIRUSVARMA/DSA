class Solution {
public:
    
    int helper(vector<int>&v)
    {
       if(v.size()==0)
       return 0;
       if(v.size()==1)
       return v[0]; 
       vector<int>dp(v.size(),0);
       dp[0]=v[0];
       dp[1]= max(v[0],v[1]);
       for(int i=2;i<v.size();i++)
       {
          dp[i]=max(v[i]+dp[i-2],dp[i-1]);
       }
      return dp[v.size()-1];
    }

    int rob(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        if(nums.size()==1)
        return nums[0];

        vector<int>v1(nums.begin()+1,nums.end());
        vector<int>v2(nums.begin(),nums.end()-1);
        
        int case1=helper(v1);
        int case2=helper(v2);

        return max(case1,case2);
    }
};
//TC:O(N)
//SC:O(N)
//Problem:https://leetcode.com/problems/house-robber-ii/

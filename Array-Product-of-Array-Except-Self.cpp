vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int>ans(n,1);
        int suf=1; int pre=1;
        for(int i=0; i<n;i++)
        {
            ans[i]*=pre;
            pre*=nums[i];
            ans[n-1-i]*=suf;
            suf*=nums[n-1-i];
        }
        return ans;
    }

//TC:O(N) SC:0(1) [Here ans vector which has a SC of O(N) is not included]
//Problem:https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
       // int n=nums.size();
       //return n*(n+1)*0.5 - accumulate(nums.begin(),nums.end(),0);
       int ans=0;
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
        ans^= (nums[i]^i);
       }
       ans=ans^n;
       return ans;
    }
};
//TC:O(N)
//SC:O(1)
//Problem:https://leetcode.com/problems/missing-number/

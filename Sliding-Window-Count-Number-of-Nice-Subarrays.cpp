class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
                unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2)
            sum++;
            //if(mp[sum-k])
            count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};

TC:O(N)
SC:O(N)
Problem:https://leetcode.com/problems/count-number-of-nice-subarrays/

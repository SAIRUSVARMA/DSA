class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            //if(mp[sum-goal]) (else would be mp[sum-goal]=0, so count+0 will still be count)
            count+=mp[sum-goal];
            mp[sum]++;
        }
        return count;
    }
};

//TC:O(N)
//SC:O(N)
//Problem:https://leetcode.com/problems/binary-subarrays-with-sum/

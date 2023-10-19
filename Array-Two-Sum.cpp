 vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            //if(mp.count(target-nums[i])>0)
            if(mp.find(target-nums[i])!=mp.end())
            return { mp[target-nums[i]] , i };
            mp[nums[i]]=i;
        }
        return {};
    }
//TC:O(N) SC:O(N) [TC:O(N^2) in worst case for unordered map, but in general it is O(N), for map it is O(NlogN)]
//https://leetcode.com/problems/two-sum/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto it:nums)
        s.insert(it);
        int ans=0;
        for(auto it:s)
        {
           if(s.find(it-1)==s.end())
           {
             int temp=1;
             int curr=it;
             while(s.find(curr+1)!=s.end())
             {
                temp++;
                curr++;
             }
             ans=max(ans,temp);
           }
        }
        return ans;
    }
};
//TC:O(N)
//SC:O(N)[For set]
//Problem:https://leetcode.com/problems/longest-consecutive-sequence/description/

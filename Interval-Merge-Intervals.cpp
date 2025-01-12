class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        for(auto interval:intervals)
        {
            if(result.empty()|| result.back()[1]<interval[0])
            result.push_back(interval);
            else
            result.back()[1]=max(result.back()[1],interval[1]);
        }
      return result;
    }
};

//TC: O(NlogN)[ O(NlogN) for sorting and O(N) for traversing, so overall O(NlogN)]
//SC: O(N)
//Problem:https://leetcode.com/problems/merge-intervals/

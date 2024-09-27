class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
       
        map<int ,int>freqmp;
        for(auto i:nums)
        {
            freqmp[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;

        for(auto it:freqmp)
        {
            minHeap.push({it.second,it.first});
            if(minHeap.size()>k)
            minHeap.pop();
        }

        vector<int>result;
        while(!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};

/*TC:O(N*logK)[where n is the number of elements in the input array.
This comes from inserting n elements into the heap and maintaining its size as k.]*/
// SC:O(N)[for the frequency map and heap storage]
//Problem:https://leetcode.com/problems/top-k-frequent-elements/description/

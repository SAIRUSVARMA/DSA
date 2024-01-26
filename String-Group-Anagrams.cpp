vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto i:strs)
        {
            string word=i;
            sort(word.begin(),word.end());
            mp[word].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto i:mp)
        ans.push_back(i.second);
        return ans;
    }

//TC:O(N*K*log(K))[Here N is number of strings, K is length of longest string, and Klog(K) is time taken for sorting].
//SC:O(N)[In worst case all strings are distinct, then we need map and ans vector of size O(N)]
//Problem:https://leetcode.com/problems/group-anagrams/description/

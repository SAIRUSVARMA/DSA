 int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int l=0;
        int r=0;
        int len=0;
        int n=s.size();
        while(r<n)
        {
            if(mp[s[r]]!=-1)
            l=max(mp[s[r]]+1,l);

            mp[s[r]]=r;
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }

//TC:O(N) SC:O(1)[Constant space of 256 characters]
//Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

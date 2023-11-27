 int characterReplacement(string s, int k) {
        int start=0; int maxCnt=0;
        vector<int>Count(26,0);
        int maxLength=0;
        for( int end=0; end<s.size(); ++end )
        {
            maxCnt=max(maxCnt, ++Count[s[end]-'A']);

            if(end-start+1 - maxCnt > k)
            {
               --Count[s[start]-'A'];
               ++start;
            }

            maxLength=max(maxLength, end-start+1);

        }
        return maxLength;
    }

//TC:O(N) SC:O(1)[We are using vector of only 26 elements O(26)=O(1)]
//Problem: https://leetcode.com/problems/longest-repeating-character-replacement/

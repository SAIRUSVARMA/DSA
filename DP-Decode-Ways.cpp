class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()|| s[0]=='0')
        return 0;
        int n=s.size()+1;
        vector<int>dp(n,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n;i++)
        {
            if(s[i-1]!='0')
            dp[i]+=dp[i-1];

            int num=stoi(s.substr(i-2,2));
            if(num>=10 && num<=26)
            dp[i]+=dp[i-2];
        }
      return dp[n-1];
    }
};
//TC:O(N)
//SC:O(N)
//Problem:https://leetcode.com/problems/decode-ways/

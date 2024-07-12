class Solution {
public:
    int countSubstrings(string s) {

        int count=0;

        vector<vector<bool>>dp(s.length(),vector<bool>(s.length(),false));

        for(int i=0;i<s.length();i++)
        {
            dp[i][i]=true;
            count++;
        }

        for(int i=0;i<s.length()-1;i++)
        {
            dp[i][i+1]=(s[i]==s[i+1]); // These Brackets () HERE are used for cleaner code, can be avoided.
            count+=dp[i][i+1];
        }

        for(int length=3; length<=s.length(); ++length)
        {
            for(int i=0, j=length-1;j<s.length();++i,++j)
            {
                dp[i][j]=dp[i+1][j-1]&&(s[i]==s[j]);// These Brackets () HERE are used for cleaner code, can be avoided.
                count+=dp[i][j];
            }
        }

        return count;

    }
};

//TC:O(N^2)
//SC:O(N^2)
//Problem:https://leetcode.com/problems/palindromic-substrings/description/

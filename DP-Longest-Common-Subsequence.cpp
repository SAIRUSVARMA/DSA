class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length()+1;
        int n=text2.length()+1;
        vector<vector<int>>v(m,vector<int>(n,0));
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    v[i][j]=1+v[i-1][j-1];
                }
                else
                {
                    v[i][j]=max(v[i-1][j],v[i][j-1]);
                }
                
            }
        }
        return v[m-1][n-1];
    }
};
//TC:O(M*N)
//SC:O(M*N)
//Problem:https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int climbStairs(int n) {
        if(n<3)
        return n;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//TC:O(N)
//SC:O(N)
---------------------------------------------------------
class Solution {
public:
    int climbStairs(int n) {
        if(n<3)
        return n;
        int a=1;
        int b=2;
        int c;
        for(int i=3;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
//TC:O(N)
//SC:O(1)[We just use 3 variables, instead of an entire array]
//Problem:https://leetcode.com/problems/climbing-stairs/description/

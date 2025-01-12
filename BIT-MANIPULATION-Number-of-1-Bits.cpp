class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0)
        {
            n= (n & n-1);
            count++;
        }
        return count;
    }
};

//TC:O(1)[O(32) in worst case as int is 32-bit]
//SC:O(1)
//Problem:https://leetcode.com/problems/number-of-1-bits/

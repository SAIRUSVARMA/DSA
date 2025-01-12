class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
          int carry= (a&b)<<1;
          a=a^b;
          b=carry;
        }
        return a;
    }
};

//TC:O(1);
//SC:O(1);
//Problem:https://leetcode.com/problems/sum-of-two-integers/

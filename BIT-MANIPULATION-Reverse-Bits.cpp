class Solution {
public:

    bool kthbitisset(int k, unsigned int A)
    {
        if(((1<<(k-1))&A)!=0)
        return true;
        return false;
    }

    uint32_t reverseBits(uint32_t n) {
        unsigned int ans=0;
        for(int i=1; i<=32;i++)
        {
            if(kthbitisset(i,n))
            {
                ans= (1<<(32-i)) | ans;
            }
        }
        return ans;
    }
};
//TC:O(1)
//SC:O(1)
//Probelem:https://leetcode.com/problems/reverse-bits/

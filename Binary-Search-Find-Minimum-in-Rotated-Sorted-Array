 int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int r=n-1;
        int ans=INT_MAX;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(nums[l]<=nums[m])
            {
                ans=min(nums[l],ans);
                l=m+1;
            }
            else
            {
                ans=min(nums[m],ans);
                r=m-1;
            }
        }
        return ans;
    }

//TC:O(log N) SC:O(1)
//Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

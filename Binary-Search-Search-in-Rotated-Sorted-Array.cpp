int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(target==nums[mid])
            return mid;

            if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target && target<=nums[mid])
                r=mid-1;
                else
                l=mid+1;
            }
            else
            {
                if(target>=nums[mid] && target<=nums[r])
                l=mid+1;
                else
                r=mid-1;
            }
        }
        return -1;
    }

//TC:O(log N) SC:O(1)
//Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum= nums[i]+nums[j]+nums[k];
                if(sum<0)
                j++;
                else if(sum>0)
                k--;
                else
                {
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                    j++;
                    while(j<k && nums[k]==nums[k+1])
                    k--;
                }
            }
        }
        return ans;
    }

//TC: O(N*logN)[For Sorting the array] + O(N^2) [For for loop and while loop inside it]
//SC: O(No of Triplets) [Thats our size of ans , we won't count temp because it only has 3 elements]
//Problem: https://leetcode.com/problems/3sum/description/

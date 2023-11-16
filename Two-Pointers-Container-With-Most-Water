 int maxArea(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int l=0;
        int r=n-1;
        while(l<r)
        {
            int b=min(height[l],height[r]);
            ans=max(ans,(r-l)*b);
            if(height[l]<height[r])
            l++;
            else
            r--;
        }
        return ans;
    }

//TC:O(N) SC:O(1)
//Problem:https://leetcode.com/problems/container-with-most-water/description/

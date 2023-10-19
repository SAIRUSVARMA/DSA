 int maxProfit(vector<int>& prices) {
        int profit=0;
        int mini=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            mini=min(prices[i],mini);
            profit=max(profit,prices[i]-mini);
        }
        return profit;
    }

//TC:O(N) SC:O(1)
//Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

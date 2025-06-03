class Solution {
public:
 int solve(vector<int>& prices, int i, int buy,int fee,vector<vector<int>>&dp) {
        if (i >= prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];

        int profit = 0;
        if (buy) { // means we can buy
            int buyItProfit = -prices[i] + solve(prices, i + 1, 0,fee,dp);  // buy kar rha hun toh paise ja rhe hai 
            int skipProfit = solve(prices, i + 1, 1,fee,dp);
            profit = max(buyItProfit, skipProfit);
        } else {
            int sellItProfit = prices[i] + solve(prices, i + 1, 1,fee,dp) -fee; // sell kar rha hun toh paise arhe hai
            int skipProfit = solve(prices, i + 1, 0,fee,dp); 
             profit = max(sellItProfit, skipProfit);
        }

        dp[i][buy]= profit;
        return  dp[i][buy];
    }

    int maxProfit(vector<int>& prices, int fee) {
         vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices, 0, 1,fee,dp); // buy ->1 we have option to buy on that day
    }
};
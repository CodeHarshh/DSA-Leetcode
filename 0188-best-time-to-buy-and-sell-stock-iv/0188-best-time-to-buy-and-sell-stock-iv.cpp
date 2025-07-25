class Solution {
public:
 int solve(vector<int>& prices, int i, int buy,vector<vector<vector<int>>>& dp,int limit,int k) {
        if (i >= prices.size() || limit==k )return 0;
        if(dp[i][buy][limit]!=-1) return  dp[i][buy][limit];


        int profit = 0;
        if (buy) { // means we can buy
            int buyItProfit = -prices[i] + solve(prices, i + 1, 0,dp,limit,k);  // buy kar rha hun toh paise ja rhe hai 
            int skipProfit = solve(prices, i + 1, 1,dp,limit,k);
            profit = max(buyItProfit, skipProfit);
        } else {
            int sellItProfit = prices[i] + solve(prices, i + 1, 1,dp,limit+1,k); // sell kar rha hun toh paise arhe hai
            int skipProfit = solve(prices, i + 1, 0,dp,limit,k); 
             profit = max(sellItProfit, skipProfit);
        }

        dp[i][buy][limit]= profit;
        return  dp[i][buy][limit];
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices, 0, 1,dp,0,k); // buy ->1 we have option to buy on that day
    }
};
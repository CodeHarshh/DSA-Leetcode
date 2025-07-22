class Solution {
public:
    // TLE MEthod
    //  TLE ayega  Will do later

    // int solve(vector<int>& coins, int amount) {
    //     if (amount == 0)  // Base Case
    //         return 0;

    //     int min_coin = INT_MAX;
    //     for (int i = 0; i < coins.size(); i++) {
    //         int coin = coins[i];

    //         if (coin <= amount) {
    //             int recursionAns = solve(coins, amount - coin);
    //             if (recursionAns != INT_MAX) {
    //                 int coinUsed = 1 + recursionAns;
    //                 min_coin = min(min_coin, coinUsed);
    //             }
    //         }
    //     }
    //     return min_coin;
    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     int ans = solve(coins, amount);
    //     if (ans == INT_MAX)  return -1;
    //     return ans;
    // }

   

    int solve(vector<int>& coins, int amount,   vector<int>&dp) {
        if (amount == 0)
            return 0;
        int min_coin = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {

            int coin = coins[i];
            if (coin <= amount) {
                int reccAns = solve(coins, amount - coin ,dp);
                if (reccAns != INT_MAX) {
                    min_coin = min(min_coin, 1 + reccAns);
                }
            }
        }
        return min_coin;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount,-1);
        int ans = solve(coins, amount,dp);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }

    // DP Method -1

    // int solve(vector<int>& coins, int amount, vector<int>&dp) {

    //     if (amount == 0)  // Base Case
    //         return 0;

    //     if(dp[amount]!=-1) return dp[amount];

    //     int min_coin = INT_MAX;
    //     for (int i = 0; i < coins.size(); i++) {
    //         int coin = coins[i];

    //         if (coin <= amount) {
    //             int recursionAns = solve(coins, amount - coin,dp);

    //             if (recursionAns != INT_MAX) {
    //                 int coinUsed = 1 + recursionAns;
    //                 min_coin = min(min_coin, coinUsed);
    //             }
    //         }
    //     }
    //     dp[amount]=min_coin;
    //     return dp[amount];
    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     vector<int>dp(amount+1,-1);
    //     int ans = solve(coins, amount,dp);
    //     if (ans == INT_MAX)  return -1;
    //     return ans;
    // }

    // DP Method -2 (bottom up approach)

    // int solve(vector<int>& coins, int amount) {
    //      vector<int>dp(amount+1,-1);
    //      dp[0]=0;

    //     for(int amt=1;amt<=amount;amt++){
    //     int min_coin = INT_MAX;

    //     for (int i = 0; i < coins.size(); i++) {
    //         int coin = coins[i];

    //         if (coin <= amt) {
    //             int recursionAns = dp[amt - coin];

    //             if (recursionAns != INT_MAX) {
    //                 int coinUsed = 1 + recursionAns;
    //                 min_coin = min(min_coin, coinUsed);
    //             }
    //         }
    //     }

    //     dp[amt]=min_coin;
    //     }

    //     return dp[amount];
    // }

    // int coinChange(vector<int>& coins, int amount) {

    //     int ans = solve(coins, amount);
    //     if (ans == INT_MAX)  return -1;
    //     return ans;
    // }

    // DP Method -3 (optimized approach)
    // not possible
};
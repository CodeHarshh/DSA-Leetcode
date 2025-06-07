class Solution {
public:
    int solve(vector<int>& nums, int i, int j, bool player1Turn, vector<vector<int>>& dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (player1Turn) {
            int pickLeft = nums[i] + solve(nums, i + 1, j, false, dp);
            int pickRight = nums[j] + solve(nums, i, j - 1, false, dp);
            dp[i][j] = max(pickLeft, pickRight);
        } else {
            int pickLeft = -nums[i] + solve(nums, i + 1, j, true, dp);
            int pickRight = -nums[j] + solve(nums, i, j - 1, true, dp);
            dp[i][j] = min(pickLeft, pickRight);
        }

        return dp[i][j];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(nums, 0, n - 1, true, dp) >= 0;
    }
};

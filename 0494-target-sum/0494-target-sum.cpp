class Solution {
public:
    // int cnt;
    // void solve(vector<int>& nums, int target, int i, long long sum) {
    //     if (i == nums.size()) {
    //         if (sum == target) {
    //             cnt++;
    //         }
    //         return;
    //     }

    //     solve(nums, target, i + 1, sum + nums[i]);
    //     solve(nums, target, i + 1, sum - nums[i]);
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     cnt = 0;
    //     solve(nums, target, 0, 0);
    //     return cnt;
    // }

int solve(vector<int>& nums, int target, int i, int sum, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return (sum == target) ? 1 : 0;
        }
        if (dp[i][sum + 1000] != -1) {   ///+1000 use to handle -ve case
            return dp[i][sum + 1000];
        }
        int add = solve(nums, target, i + 1, sum + nums[i], dp);
        int subtract = solve(nums, target, i + 1, sum - nums[i], dp);
        return dp[i][sum + 1000] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, -1));
        return solve(nums, target, 0, 0, dp);
    }

};
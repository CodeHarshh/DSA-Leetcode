class Solution {
public:
    // TLE Method
    // int solve(vector<vector<int>>& mat, int sum, int row, int& target) {
    //     // when row iteration goes out of bound
    //     if (row == mat.size())
    //         return abs(target - sum);

    //     int ans = INT_MAX;
    //     for (int col = 0; col < mat[row].size(); col++) {
    //         int recurAns = solve(mat, sum + mat[row][col], row + 1, target);
    //         ans = min(recurAns, ans);
    //     }
    //     return ans;
    // }

    // int minimizeTheDifference(vector<vector<int>>& mat,int target) {
    //               int sum = 0, row = 0;

    //               return solve(mat, sum, row, target);
    //           }

    int solve(vector<vector<int>>& mat, int sum, int row, int& target,
              vector<vector<int>>& dp) {
        int ans = INT_MAX;
        if (row >= mat.size())return abs(target - sum);
        if (dp[sum][row] != -1) return dp[sum][row];

        for (int col = 0; col < mat[row].size(); col++) {
            int recAns = solve(mat, sum + mat[row][col], row + 1, target,
                               dp); // return value come here
            ans = min(ans, recAns);
        }

        dp[sum][row] = ans;
        return dp[sum][row];
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int sum = 0, row = 0;
        int maxSum = 0;
        for (const auto& row : mat) {
            maxSum += *max_element(row.begin(), row.end());
        }
        vector<vector<int>> dp(maxSum + 1, vector<int>(mat.size(), -1));
        return solve(mat, sum, row, target, dp);
    }
};
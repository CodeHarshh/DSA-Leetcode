class Solution {
public:
    int issolve(vector<int>& nums, int n, int i,
                vector<int>&dp) {
        if (i > n) return INT_MAX;
        if (i >= n) return 0;
        if (nums[i] == 0) return INT_MAX;             
        if (dp[i] != -1) return dp[i];

        int minJump = INT_MAX;

        for (int j = 1; j <= nums[i]; j++) {
            int recAns = issolve(nums, n, i + j, dp);
            if (recAns != INT_MAX) {
                minJump = min(minJump, 1+ recAns);
            }
        }

        dp[i] = minJump;
        return dp[i];
    }

    int jump(vector<int>& nums) {
        
        int n = nums.size() - 1;
        vector<int>dp(n+1,-1);
         return issolve(nums, n, 0, dp);
    }
};
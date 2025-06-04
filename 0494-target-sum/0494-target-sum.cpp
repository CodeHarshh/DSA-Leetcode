class Solution {
public:
    int cnt;
    void solve(vector<int>& nums, int target, int i, long long sum) {
        if (i == nums.size()) {
            if (sum == target) {
                cnt++;
            }
            return;
        }

        solve(nums, target, i + 1, sum + nums[i]);
        solve(nums, target, i + 1, sum - nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        cnt = 0;
        solve(nums, target, 0, 0);
        return cnt;
    }
};
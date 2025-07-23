class Solution {
public:
    // int solve(vector<int>& nums, int n, int i, int cnt) {
    //     if (i >= n)
    //         return cnt;
    //     if (nums[1] == 0)
    //         return INT_MAX;

    //     int min_jump = INT_MAX;

    //     // j== jump
    //     for (int j = 1; j <= nums[i]; j++) {
    //         int ans = solve(nums, n, i + j, cnt + 1);
    //         if (ans != INT_MAX) {
    //             min_jump = min(min_jump, ans);
    //         }
    //     }
    //     return min_jump;
    // }

    int jump(vector<int>& nums) {
 int jumps = 0;
        int currentEnd = 0;
        int furthest = 0;

        for (int i = 0; i < nums.size() - 1; ++i) { // O(n) loop
            // Update the furthest point we can reach
            furthest = std::max(furthest, i + nums[i]);

            // If we have reached the end of the current range
            if (i == currentEnd) {
                jumps++;
                currentEnd = furthest;

                // If the current end reaches or exceeds the last index
                if (currentEnd >= nums.size() - 1) {
                    break; // Exit the loop early if end is reached
                }
            }
        }

        return jumps;

        // int cnt = 0;
        // int n = nums.size() - 1;
        // return solve(nums, n, 0, cnt);
    }
};
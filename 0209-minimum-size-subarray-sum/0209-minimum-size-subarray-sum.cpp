class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int j = 0;
        int i = 0;
        int len = INT_MAX;
        while (i < nums.size() && j < nums.size()) {

            sum = sum + nums[i++];
            while (sum >= target) {
                    len = min(len,  i-j);
                sum = sum - nums[j++];
            }
        }
        return (len == INT_MAX) ? 0 : len;
    }
};
class Solution {
public:
    bool issolve(vector<int>& nums, int n, int i) {
        if (i == n)
            return true;
        if (i > n)
            return false;
        if (nums[i] == 0)
            return false;
        bool recAns = false;
        for (int jump = 1; jump <=nums[i]; jump++) {
            recAns = recAns || issolve(nums, n, i + jump);
        }
        return recAns;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;

        return issolve(nums, n, 0);
    }
};
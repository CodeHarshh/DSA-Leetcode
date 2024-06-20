class Solution {
public:

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> s;
        int i = 0, j = 1;
        while ( j < nums.size()) {
            int diff = abs(nums[i] - nums[j]);
            if (diff == k) {
                s.insert({nums[i], nums[j]});
                i++;
                j++;
            } else if (diff < k) {
                j++;
            } else {

                i++;
            }
            if (i == j) {
                j++;
            }
        }
        return s.size();
    }
};

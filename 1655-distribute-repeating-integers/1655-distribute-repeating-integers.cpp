class Solution {
public:
    bool solve(vector<int> counts, vector<int>& quantity, int ithcustomer) {
        if (ithcustomer == quantity.size()) {
            return true;
        }
        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] >= quantity[ithcustomer]) {
                counts[i] = counts[i] - quantity[ithcustomer];
                if (solve(counts, quantity, ithcustomer + 1)) {
                    return true;
                }
                counts[i] = counts[i] + quantity[ithcustomer];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> m;
        for (auto it : nums) {
            m[it]++;
        }
        vector<int> counts;
        for (auto it : m) {
            counts.push_back(it.second);
        }
        sort(quantity.rbegin(),quantity.rend());
        return solve(counts, quantity, 0);
    }
};
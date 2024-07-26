class Solution {
public:
    void solve(int n, int k, int st, vector<int>& curr,
               vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = st; i <= n; i++) {
            curr.push_back(i);
            solve(n, k - 1, i + 1, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(n, k, 1, curr, ans);
        return ans;
    }
};
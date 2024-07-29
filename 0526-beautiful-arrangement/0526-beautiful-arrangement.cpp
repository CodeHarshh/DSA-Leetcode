class Solution {
public:
    void solve(vector<int>& v, int& ans, int& n, int currno) {
        if (currno == n + 1) {
            ans++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (v[i] == 0 && (currno % i == 0 || i % currno == 0)) {
                v[i] = currno;
                solve(v, ans, n, currno + 1);
                // backtrack
                v[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> v(n + 1, 0);
        int ans = 0;
        solve(v, ans, n, 1);
        return ans;
    }
};
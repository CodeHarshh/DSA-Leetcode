class Solution {
public:
    void convertStrToNum(vector<string>& strs,
                         vector<pair<int, int>>& numStrs) {
        for (auto str : strs) {
            int Zeros = 0, Ones = 0;
            for (auto ch : str) {
                if (ch == '0')
                    Zeros++;
                else
                    Ones++;
            }
            numStrs.push_back({Zeros,Ones});
        }
    }

    int solve(vector<pair<int, int>>& numStrs, int m, int n, int i, vector<vector<vector<int>>>&dp) {
        if (i == numStrs.size()) return 0;

        if(dp[m][n][i]!=-1) return dp[m][n][i];

        int Zeros = numStrs[i].first, Ones = numStrs[i].second;
        int include = 0;
        if (m >= Zeros && n >= Ones) {
            include = 1 + solve(numStrs, m - Zeros, n - Ones, i + 1,dp);
        }
        int exclude = solve(numStrs, m, n, i + 1,dp);
     
        dp[m][n][i]= max(include, exclude);
        return dp[m][n][i];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> numStrs; // <no of 0's , no of 1's>
        convertStrToNum(strs, numStrs);
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(numStrs.size(),-1)));
        return solve(numStrs, m, n, 0,dp);
    }
};
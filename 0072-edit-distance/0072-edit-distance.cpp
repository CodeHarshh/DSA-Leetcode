class Solution {
public:
    int solve(string& w1, string& w2, int i, int j, vector<vector<int>>&dp) {

        // if w1 is finished → insert all remaining chars of w2
        if (i >= w1.size()) return w2.size() - j;

        // if w2 is finished → delete all remaining chars of w1
        if (j >= w2.size()) return w1.size() - i;

        int ans = 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if (w1[i] == w2[j]) {
            return solve(w1, w2, i + 1, j + 1,dp);
        }

        int insertion = 1 + solve(w1, w2, i, j + 1,dp); // insertion

        int deletion = 1 + solve(w1, w2, i + 1, j,dp); // deletion

        int replace = 1 + solve(w1, w2, i + 1, j + 1,dp); // replace

        dp[i][j] = min(insertion, min(deletion, replace));
        return dp[i][j];
    }

    int minDistance(string w1, string w2) {
        int n=w1.size()+w2.size();
         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
         return solve(w1, w2, 0, 0,dp); 
         }
};
class Solution {
public:
// lb dp assingment
    int solve(string& s, string& t, int i, int j,vector<vector<int>>&dp) {

        if (j >= t.size())return 1;
        if (i >= s.size())return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;

        if (s[i] == t[j]) {
            ans = ans + solve(s, t, i + 1, j + 1,dp); // if both matches move i and j by 1 each
            }
            ans = ans + solve(s, t, i + 1, j,dp);  // skip i+1  
        
        dp[i][j]=ans;
        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int n=s.size();int m=s.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s, t, 0, 0,dp);
    }
};
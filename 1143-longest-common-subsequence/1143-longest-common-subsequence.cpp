class Solution {
public:
    ////// TLE method
/// dp-1
    int solve(string& t1, string& t2, int i, int j, vector<vector<int>>&dp) {
        if (i >= t1.size()) return 0;
        if (j >= t2.size()) return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int ans = 0;

        if (t1[i] == t2[j]) {
            ans = 1 + solve(t1, t2, i + 1, j + 1,dp);
        } else {
            ans = 0 + max(solve(t1, t2, i + 1, j,dp), solve(t1, t2, i, j + 1,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string t1, string t2) {
        vector<vector<int>>dp(t1.size()+1, vector<int>(t2.size()+1,-1));
        int i = 0, j = 0;
        return solve(t1, t2, i, j,dp);
    }

    // int solve(string &text1, string &text2,int i,int j){
    //         if(i>=text1.size()) return 0;
    //         if(j>=text2.size()) return 0;

    //         int ans=0;
    //         // match case
    //         if(text1[i]==text2[j])
    //           ans=1+solve(text1,text2,i+1,j+1);

    //        // no match case
    //        if(text1[i]!=text2[j])
    //       ans=0 + max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));

    //         return ans;

    //          }
    //     int longestCommonSubsequence(string text1, string text2) {
    //         int cnt=0;
    //         int i=0,j=0;
    //        return solve(text1,text2,i,j);
    //     }

    // m2 - memoziation dp method 1
    // int solve(string &text1, string &text2,int i,int j,
    // vector<vector<int>>&dp){

    //         if(i>=text1.size()) return 0;
    //         if(j>=text2.size()) return 0;

    //         if(dp[i][j]!=-1){
    //             return dp[i][j];
    //         }

    //         int ans=0;
    //         // match case
    //         if(text1[i]==text2[j])
    //           ans=1+solve(text1,text2,i+1,j+1,dp);

    //        // no match case
    //        if(text1[i]!=text2[j])
    //       ans=0 +
    //       max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
    //        dp[i][j]=ans;
    //         return dp[i][j];

    //          }
    //     int longestCommonSubsequence(string text1, string text2) {
    //         int i=0,j=0;
    //         vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
    //        return solve(text1,text2,i,j,dp);
    //     }

    // m3 - tabulation dp method 2
    // int solve(string &text1, string &text2){
    //      vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
    //      //already taken her zero

    //          for(int i=text1.size()-1;i>=0;i--){
    //              for(int j=text2.size()-1;j>=0;j--){

    //         int ans=0;
    //         // match case
    //         if(text1[i]==text2[j])
    //           ans=1+ dp[i+1][j+1];

    //        // no match case
    //        if(text1[i]!=text2[j])
    //       ans=0 + max(dp[i+1][j],dp[i][j+1]);
    //        dp[i][j]=ans;

    //          }
    //          }

    //         return dp[0][0];

    //          }
    //     int longestCommonSubsequence(string text1, string text2) {
    //        return solve(text1,text2);
    //     }

    // // m4 Dp  - method 3 (optimization method)
    // int solve(string &text1, string &text2){
    //     //
    //     vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
    //     //already taken her zero vector<int>prev(text2.size()+1,0);
    //     vector<int>curr(text2.size()+1,0);

    //          for(int i=text1.size()-1;i>=0;i--){
    //              for(int j=text2.size()-1;j>=0;j--){

    //         int ans=0;
    //         // match case
    //         if(text1[i]==text2[j])
    //           ans=1+ prev[j+1];

    //        // no match case
    //        if(text1[i]!=text2[j])
    //       ans=0 + max(prev[j],curr[j+1]);
    //        curr[j]=ans;

    //          }  prev=curr;

    //          }

    //         return prev[0];

    //          }
    //     int longestCommonSubsequence(string text1, string text2) {
    //        return solve(text1,text2);
    //     }
};
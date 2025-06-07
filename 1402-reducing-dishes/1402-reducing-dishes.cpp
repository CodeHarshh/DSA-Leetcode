class Solution {
public:
        int solve(vector<int>& sat,int i , int T ,vector<vector<int>>&dp){
         if(i==sat.size()) return 0;
         if(dp[i][T]!=-1) return dp[i][T];
         int include = T * sat[i] +solve(sat,i+1,T+1,dp);
         int exclude = solve(sat,i+1,T,dp);
          return dp[i][T]=max(include,exclude);
         }
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        vector<vector<int>>dp(sat.size(),vector<int>(sat.size() +1 , -1));
        return solve(sat,0,1,dp);
    }
};
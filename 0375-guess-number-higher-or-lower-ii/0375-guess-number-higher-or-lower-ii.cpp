class Solution {
public:
//  Lb L-5(DP)  //// TOP Down Approach
//     int SolveRecur(int s, int e,vector<vector<int>>&dp){
//         if(s>=e)return 0;

//         int maxi=INT_MAX;
//         if(dp[s][e]!=-1) return dp[s][e];

//         for(int i=s;i<=e;i++){
//             maxi=min(maxi,i + max(SolveRecur(s,i-1,dp) , SolveRecur(i+1,e,dp)));
//         }
//        dp[s][e]=maxi;
//          return dp[s][e];
//     }
//     int getMoneyAmount(int n) {
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         int ans=SolveRecur(1,n,dp);
//         return ans;
        
//   Tabulation aPProach (dp method-2)

    int SolveRecur(int n){
         vector<vector<int>>dp(n+1,vector<int>(n+1,0));


         for(int s=n;s>=1;s--){
           for(int e=1;e<=n;e++){
            if(s>=e){continue;}
            else {
                int maxi=INT_MAX;
                for(int i=s;i<e;i++){
                    maxi=min(maxi,i + max(dp[s][i-1] , dp[i+1][e]));
                }
                dp[s][e]=maxi;

            }
           }
         }



         return dp[1][n];
    }

    int getMoneyAmount(int n) {
       
        int ans=SolveRecur(n);
        return ans;
        
    }
};
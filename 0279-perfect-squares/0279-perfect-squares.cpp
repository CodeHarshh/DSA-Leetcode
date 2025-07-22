class Solution {
public:
    int solve(int n, vector<int>&dp) {
      if(n<=0)return 0;
      if(n==1)return 1;
       
      if(dp[n]!=-1)return dp[n]; 

      int ans=INT_MAX;

      int end=sqrt(n);
      for(int i=1;i<=end;i++){
        int square=i*i;
        int recurrAns=1+solve(n-square,dp);
        if(recurrAns<ans) ans=recurrAns;
      }
      dp[n]=ans;
      return dp[n];
    }

    int numSquares(int n) {
        vector<int>dp(n+1,-1);
         return solve(n,dp); 
         }

    // normal recussion method

    //          int solve(int n) {
    //     if (n == 1) return 1 ;
    //     if (n <1) return 0;

    //     int ans = INT_MAX;
    //     int i = 1;
    //     int end = sqrt(n);
    //     while (i <= end) {
    //         int perfect_square = i * i;
    //         int noOfPerfectSquare = 1 + solve(n - perfect_square);
    //         if (noOfPerfectSquare < ans) {
    //             ans = noOfPerfectSquare;
    //         }
    //         i++;
    //     }
    //     return ans;
    // }

    // int numSquares(int n) {
    //      return solve(n) ;
    //      }

    /// dp method -1   tc- > o(n)  and sc->o(n)
    // int solve(int n,  vector<int>&dp) {
    //     if(n<=0)return 0;
    //     if(dp[n]!= -1 )return dp[n];
    //     int ans=INT_MAX;
    //     int i=1;
    //     int end=sqrt(n);
    //     while(i<=end){
    //         int perfect_square=i*i;
    //         int perfect_square_no=1+solve(n-perfect_square);
    //         if(perfect_square_no<ans){
    //             ans=perfect_square_no;
    //         }
    //         i++;
    //     }
    //     dp[n] =ans;
    //     return dp[n];
    // }

    // int numSquares(int n) {
    //     vector<int>dp(n+1,-1);
    //      return solve(n,dp) ;
    //      }
};
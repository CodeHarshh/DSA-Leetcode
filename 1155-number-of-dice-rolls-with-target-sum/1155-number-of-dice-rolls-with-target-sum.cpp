class Solution {
public:
// const int mod = 1e9 + 7;;
    // TLE
    // n no of dice & k no of face  

    // long long int solve(int n, int k, int target) {
    //     if (target < 0)return 0;
    //     if (n == 0 && target != 0)return 0;
    //     if (target == 0 && n != 0)return 0;
    //     if (target == 0 && n == 0)return 1;

    //     long long int ans = 0;
    //     for (int i = 1; i <= k; i++) {
    //         ans = ans + solve(n - 1, k, target - i);
    //     }
    //    return ans;
    // }
    // int numRollsToTarget(int n, int k, int target) {
    // return  solve(n,k,target);
    // }


const int mod=1e9+7;

    long long int solve(int n, int k, int target,vector<vector<int>>&dp) {
        if(n==0 && target==0) return 1;
        if(n==0 && target!=0) return 0;
        if(n!=0 && target==0) return 0;
        if(target<0) return 0;

        if(dp[n][target]!=-1) return dp[n][target];
      
       int ans=0;
        for(int i=1;i<=k;i++){
          
          if(i<=target){
            ans=(ans+ solve(n-1,k,target-i,dp))%mod;
          }
        }
         dp[n][target]= ans;
   return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans= (int)solve(n,k,target,dp);

   return ans;
    }

// solve using memoazation dp-method-1>

    //   long long int solve(int n, int k, int target,vector<vector<long long int >>&dp) {
    //     if (target < 0)
    //         return 0;
    //     if (n == 0 && target != 0)
    //         return 0;
    //     if (target == 0 && n != 0)
    //         return 0;
    //     if (target == 0 && n == 0)
    //         return 1;

    //     if(dp[n][target]!=-1){
    //         return dp[n][target];
    //    }   

    //     long long int ans = 0;
    //     for (int i = 1; i <= k; i++) {
    //         ans = ans + solve(n - 1, k, target - i,dp);
    //     }
    //     dp[n][target]=ans % mod;
    //     return dp[n][target];
    // }
    // int numRollsToTarget(int n, int k, int target) {

    // vector<vector<long long int >>dp(n+1,vector<long long int >(target+1,-1));
    // return  solve(n,k,target,dp);
    // } 


//  // solve using Tabulation ( dp-method->2 )

    //   long long int solveusingTabulation(int n, int k, int target) {
    //    vector<vector<long long int >>dp(n+1,vector<long long int >(target+1,0));
    //    dp[0][0]=1;

    //    for(int N=1;N<=n;N++){
    //     for(int T=1;T<=target;T++){
    //             long long int ans = 0;
    //             for (int i = 1; i <= k; i++) {
    //                 int localAns=0;
    //                 if(T-i>=0 ){
    //                      ans = (ans + dp[N - 1][T - i]) % mod; 
    //                 }
                   
    //             }
    //             dp[N][T]=ans % mod;
    //     } 
    //    } 

       
    //     return dp[n][target];
    // }
    // int numRollsToTarget(int n, int k, int target) {

    // return  solveusingTabulation(n,k,target);
    // }   

    //  sapce  optimization  dp method -3

    //  long long int optimization(int n, int k, int target) {

    //    vector<long long int>prev(target+1,0);
    //    vector<long long int>curr(target+1,0);

    //    prev[0]=1;

    //    for(int N=1;N<=n;N++){
    //     for(int T=1;T<=target;T++){
    //             long long int ans = 0;
    //             for (int i = 1; i <= k; i++) {
    //                 int localAns=0;
    //                 if(T-i>=0 ){
    //                      ans = (ans + prev[T - i]) % mod; 
    //                 }
                   
    //             }
    //             curr[T]=ans % mod;
    //     } prev=curr;
    //    } 
    
       
    //     return prev[target];
    // }
    // int numRollsToTarget(int n, int k, int target) {

    // return  optimization(n,k,target);
    // }   
};
// Method 1 (Normal Recursion)
// class Solution {
// public:
//     int fib(int n) {
//         if(n==1) return 1;
//         if(n==0) return 0;
//         return fib(n-1)+fib(n-2);
//     }
// };

// Method 2(DP)

// class Solution {
// public:
//     int solve(int n, vector<int>& dp) {
//         if (n == 0)return 0;
//         if (n == 1)return 1;

//         if (dp[n] != -1) {
//             return dp[n];
//         }
//         dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
//         return dp[n];
//     }

//     int fib(int n) {
//         vector<int> dp(n + 1, -1);
//        return solve(n, dp);
        
//     }
// };



/// solve using tabulation

class Solution {
public:
    int solveUsingTabulation(int n) {
        if(n<1) return 0;
         vector<int> dp(n + 1, -1);
         dp[0]=0;
         dp[1]=1;

         for(int i=2;i<=n;i++){
              dp[i] = dp[i - 1] + dp[i - 2];
         }
    
        return dp[n];
    }

    int fib(int n) {
       return solveUsingTabulation(n);
        
    }
};
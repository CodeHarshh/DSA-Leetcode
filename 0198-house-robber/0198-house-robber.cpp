class Solution {
public:
   int solve(vector<int>&nums,int i,int n, vector<int>&dp){
    if(i>=n) return 0;
     
     if(dp[i]!=-1) return dp[i];
    int take=nums[i]+solve(nums,i+2,n,dp);
    int not_take=0+solve(nums,i+1,n,dp);
    
    dp[i]=max(take,not_take);
    return dp[i];
   }

    int rob(vector<int>& nums) {
      int n=nums.size();
        vector<int>dp(n,-1);
      int i=0;
      return solve(nums,i,n,dp);
    }



// solved using recurrsion (TLE)


// class Solution {
// public:

// int solve(vector<int>& nums,int i,int n){
// // Lb TLE will do in DP
// if(i>=n) return 0;

// int part1=nums[i]+solve(nums,i+2,n);
// int part2=0+ solve(nums,i+1,n);

// return max(part1,part2);
// }
//   int rob(vector<int>& nums) {
//      int n=nums.size();
//    int ans=solve(nums,0,n);
//    return ans;
//     }

// };

// DP - method -> 1
// 1D Dp  Top down approach
// class Solution {
// public:

// int solve(vector<int>& nums,int i,int n,vector<int>&dp){

// if(i>=n) return 0;
// if(dp[i]!=-1)return dp[i];

// int part1=nums[i]+solve(nums,i+2,n,dp);
// int part2=0+ solve(nums,i+1,n,dp);
// dp[i]=max(part1,part2);
// return dp[i];
// }

//   int rob(vector<int>& nums) {
//     int n=nums.size();
//     vector<int>dp(n+1,-1);
//    int ans=solve(nums,0,n,dp);
//    return ans;
//     }
// };



// DP - method -> 2
// 1D Dp  Bottom Up approach
// class Solution {
// public:
//     int TabulationApproach(vector<int>& nums, int i, int n) {
//         vector<int> dp(n + 2, 0);
//         dp[n] = 0;

//         for (int i =n-1; i >= 0; i--) {
//             int part1 = nums[i] + dp[i + 2];
//             int part2 = 0 + dp[i + 1];
//             dp[i] = max(part1, part2);
//         }
//         return dp[0];    // always return the last filled block or value
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         int ans = TabulationApproach(nums, 0,n);
//         return ans;
//     }
// };


// DP - method -> 3
// 1D Dp  Optimization approach
// class Solution {
// public:
//     int Optimization(vector<int>& nums, int i, int n) {
//         // vector<int> dp(n + 2, 0);
//         // dp[n] = 0;
//         int iplusone=0,iplusTwo=0,maxim;
//         for (int i =n-1; i >= 0; i--) {
//             int part1 = nums[i] + iplusTwo;
//             int part2 = 0 + iplusone;
//             maxim = max(part1, part2);
//             iplusTwo=iplusone;
//             iplusone=maxim;

//         }
//         return maxim;    // always return the last filled block or value
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         int ans = Optimization(nums, 0,n);
//         return ans;
//     }
};


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
//1D Dp  Top down approach
class Solution {
public:

int solve(vector<int>& nums,int i,int n,vector<int>&dp){
    
if(i>=n) return 0;
if(dp[i]!=-1)return dp[i];

int part1=nums[i]+solve(nums,i+2,n,dp);
int part2=0+ solve(nums,i+1,n,dp);
dp[i]=max(part1,part2);
return dp[i];
}

  int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n+1,-1);
   int ans=solve(nums,0,n,dp);
   return ans;
    }
};
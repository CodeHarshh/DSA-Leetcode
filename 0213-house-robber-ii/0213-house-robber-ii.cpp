class Solution {
public:
// Lb TLE will do in DP
//   int solve(vector<int>& nums,int s,int e){
// // here chnage from s>=e to s>e
// if(s>e) return 0;

// int part1=nums[s]+solve(nums,s+2,e);
// int part2=0+ solve(nums,s+1,e);

// int finalans=max(part1,part2);
// return finalans;
// }    

//     int rob(vector<int>& nums) {
//           int n=nums.size()-1;
//           if(n==1) return nums[0];
//           int pt1=solve(nums,0,n-1);
//           int pt2=solve(nums,1,n);
    
//     return max(pt1,pt2); 
//     }



  int solve(vector<int>& nums,int s,int e,vector<int>&dp){
   
   if(s>e) return 0;
   if(dp[s]!=-1) return dp[s];
   int part1=nums[s]+solve(nums,s+2,e,dp);
   int part2=0+solve(nums,s+1,e,dp);

  dp[s]=max(part1,part2);
  return dp[s];
}    

    int rob(vector<int>& nums) {
         int n=nums.size()-1;
         vector<int>dp(n+2,-1);
         if(nums.size()==1) return nums[0];
         int a=solve(nums,1,n,dp);
         int b=solve(nums,0,n-1,dp);
         return max (a,b);
    }
};
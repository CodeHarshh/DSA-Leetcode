class Solution {
public:

    //  TLE
//  bool solve(vector<int>& nums, int target, int i) {
//         if (target < 0 || i == nums.size())
//             return false;
//         if (target == 0)
//             return true;

//         bool inc = solve(nums, target - nums[i], i + 1);
//         bool exc = solve(nums, target, i + 1);
//         return inc || exc;
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(),0);
//         if (sum % 2 != 0)
//             return false;

//         int target = sum / 2;
//         return solve(nums,target,0);
//     }



 bool solve(vector<int>& nums, int target, int i) {
    if(target==0) return true;
    if(target<0) return false;
    if(i>=nums.size()) return false;
     
    //  if(nums[i<=target]){
        bool inc=solve(nums,target-nums[i],i+1);
    //  }
    
    bool exc=solve(nums,target,i+1);

    return inc||exc;
    }

    bool canPartition(vector<int>& nums) {
       int sum=0;
       for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
       }
       if(sum%2!=0) return false;
       int target=sum/2;
      return solve(nums,target,0);
    }













// DP MEthod-1 
//bool solve(vector<int>& nums, int target, int i, vector<vector<int>>&dp) {
//         if (target < 0 || i == nums.size()) return false;
//         if (target == 0) return true;

//         if(dp[target][i]!=-1) return dp[target][i];
       
//         bool inc = solve(nums, target - nums[i], i + 1,dp);
//         bool exc = solve(nums, target, i + 1,dp);
//         dp[target][i]=inc || exc;
//         return dp[target][i];
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(),0);
//         if (sum % 2 != 0) return false;
//         int n=nums.size()-1;
//         int target = sum / 2;
//         vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
//         return solve(nums,target,0,dp);
//     }


// Methos -2 using tabulation 

//bool solveusingTabulation(vector<int>& nums, int target, int i) {
//int n=nums.size();
//      vector<vector<bool>>dp(target+1,vector<bool>(n+1,0));

//         for(int col=0;col<=nums.size();col++){ // if (target == 0) return true;  zero th row me sb ko true set krna ha;
//             dp[0][col]=true;
//         }

//      for (int t = 1; t <= target; t++) {
//         for (int i = n - 1; i >= 0; i--) {
//            bool inc = 0;
//             if(t - nums[i] >=0){
//                 inc=dp[t - nums[i]][i + 1];
//             }
//         bool exc = dp[t][i + 1];
//         dp[t][i]=inc || exc;
//             }
//         }
        
//         return dp[target][0];
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(),0);
//         if (sum % 2 != 0) return false;
      
//         int target = sum / 2;
       
//         return solveusingTabulation(nums,target,0);
//     }


// mehtod 3 (space optimization)

// bool Optimization(vector<int>& nums, int target, int i) {
//   int n=nums.size();
//     vector<int>curr(target+1,0);
//     vector<int>next(target+1,0);

//         for(int col=0;col<=nums.size();col++){ // if (target == 0) return true;  zero th row me sb ko true set krna ha;
//             next[0]=true;
//         }

    
//         for (int i = n - 1; i >= 0; i--) {
//              for (int t = 1; t <= target; t++) {
//            bool inc = 0;
//             if(t - nums[i] >=0){
//                 inc=next[t - nums[i]];
//             }
//         bool exc = next[t];
//         curr[t]=inc || exc;
       

//             } next=curr;
//         }
        
//         return next[target];
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(),0);
//         if (sum % 2 != 0) return false;
      
//         int target = sum / 2;
       
//         return Optimization(nums,target,0);
//     }
};
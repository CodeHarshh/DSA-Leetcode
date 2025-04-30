class Solution {
public:
//  most optimal approach   tc- o(log n)
int solve(vector<int>& nums){
vector<int>ans;
ans.push_back(nums[0]);

for(int i=1;i<nums.size();i++){
    if(nums[i]>ans.back()){ ans.push_back(nums[i]);}
    else{
auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
int idx = it - ans.begin();
ans[idx]=nums[i];
    }
}
    return ans.size();

}
    int lengthOfLIS(vector<int>& nums) {
       
        return solve(nums);
    }



// tc: o(n^2)
/////// 2d DP    we are changning i as well as last (both parameter are changing
    // ) Method 1 : 1 TLE int solve(vector<int>& nums,int i,int lastindx){
    // if(i>=nums.size())return 0;

    // int curr=nums[i];
    // int include=0;

    // if(lastindx ==-1 || curr>nums[lastindx]){

    //  include=1+solve(nums,i+1,i);
    // }
    // int exclude=0+solve(nums,i+1,lastindx);

    // return max(include,exclude);

    // }

/////////////
// int solveMem(vector<int>& nums, int i, int lastindx,
//                  vector<vector<int>>& dp) {

//         if (i >= nums.size())
//             return 0;

//         if (dp[i][lastindx + 1] != -1)
//             return dp[i][lastindx + 1]; // why index+1 ? becoz if we take +1
//                                         // index cant be -1 it will be +ve

//         int curr = nums[i];
//         int include = 0;

//      if (lastindx == 0 || curr > nums[lastindx - 1]) {

//             include = 1 + solveMem(nums, i + 1, i, dp);
//         }
//         int exclude = 0 + solveMem(nums, i + 1, lastindx, dp);

//         dp[i][lastindx + 1] = max(include, exclude);
//         return dp[i][lastindx + 1];
//     }

    // int solveTablulation(vector<int>& nums, int lastindx,
    //                      vector<vector<int>>& dp) {
    //     int n = nums.size();
    //     for (int row = 0; row < n + 3; row++) {
    //         dp[row][n] = 0; // analysis base case
    //     }

    //     for (int LastINDX = n + 1; LastINDX >= 0; LastINDX--) {
    //         for (int i = n - 1; i >= 0; i--) {

    //             int curr = nums[i];
    //             int include = 0;

    //             if (lastindx == -1 || curr > nums[lastindx-1]) {

    //                 include = 1 + dp[i + 1][i + 1];
    //             }
    //             int exclude = 0 + dp[i + 1][lastindx + 1];

    //             dp[i][lastindx + 1] = max(include, exclude);
    //         }
    //     }
    //     return dp[0][0];
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int lastindx = -1;
    //     int n = nums.size();
    //     vector<vector<int>> dp(n + 3, vector<int>(n + 1, -1));
    //     return solveTablulation(nums, lastindx, dp);
    // }
};
class Solution {
public:
    // Lb L-4 DP
    // bool issafe(vector<int> v1, vector<int> v2) {
    //     if (v1[0] <= v2[0] && v1[1] <= v2[1] && v1[2] <= v2[2])
    //         return true;
    //     return false;
    // }

    // int solve(vector<vector<int>>& cuboids, int curr, int prev) {
    //     if (curr >= cuboids.size())
    //         return 0;

    //     int include = 0;
    //     if (prev == -1 || issafe(cuboids[prev], cuboids[curr])) {
    //         include = cuboids[curr][2] + solve(cuboids, curr + 1, curr);
    //     }
    //     int exclude = 0 + solve(cuboids, curr + 1, prev);
    //     int final_ans = max(include, exclude);

    //     return final_ans;
    // }

    // int maxHeight(vector<vector<int>>& cuboids) {
    //     for (auto& it : cuboids) { // first sort all the vectors indivisually
    //         sort(it.begin(), it.end());
    //     }

    //     sort(cuboids.begin(), cuboids.end());
    //     int curr = 0,prev = -1;
    //     int ans = solve(cuboids, curr, prev,dp);
    //     return ans;
    // }









     // DP Method 1
    //    bool issafe(vector<int> v1, vector<int> v2) {
    //     if (v1[0] <= v2[0] && v1[1] <= v2[1] && v1[2] <= v2[2])
    //         return true;
    //     return false;
    // }

    // int Solvememoization(vector<vector<int>>& cuboids, int curr, int prev,vector<vector<int>>&dp) {
    //     if (curr >= cuboids.size())
    //         return 0;

    //     if(dp[curr][prev+1]!=-1){
    //         return dp[curr][prev+1];
    //     }    

    //     int include = 0;
    //     if (prev == -1 || issafe(cuboids[prev], cuboids[curr])) {
    //         include = cuboids[curr][2] + Solvememoization(cuboids, curr + 1, curr,dp);
    //     }
    //     int exclude = 0 + Solvememoization(cuboids, curr + 1, prev,dp);
    //     dp[curr][prev+1] = max(include, exclude);

    //     return dp[curr][prev+1];
    // }

    // int maxHeight(vector<vector<int>>& cuboids) {
    //     int n=cuboids.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

    //     for (auto& it : cuboids) { // first sort all the vectors indivisually
    //         sort(it.begin(), it.end());
    //     }

    //     sort(cuboids.begin(), cuboids.end());
    //     int curr = 0,prev = -1;
    //     int ans = Solvememoization(cuboids, curr, prev,dp);
    //     return ans;
    // }






    // DP method 2 Tabulation
    //        bool issafe(vector<int> v1, vector<int> v2) {
    //     if (v1[0] <= v2[0] && v1[1] <= v2[1] && v1[2] <= v2[2])
    //         return true;
    //     return false;
    // }

    // int SolveTabulation(vector<vector<int>>& cuboids, int curr,int prev) {
    //      int n=cuboids.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
 
    //     for(int curr=n-1;curr>=0;curr--){
    //          for(int prev=n-1;prev>=-1;prev--){
    //             int include = 0;
    //             if (prev == -1 || issafe(cuboids[prev], cuboids[curr])) {
    //                 include = cuboids[curr][2] + dp[curr + 1][curr+1];
    //             }
    //             int exclude = 0 + dp[curr + 1] [prev+1];
    //             dp[curr][prev+1] = max(include, exclude);
    //          }
    //     }

    //     if (curr >= cuboids.size())
    //         return 0;       

    //     return dp[0][-1+1]; // ab yaha +1 kiya hai toh har right wale me +1
    // }

    // int maxHeight(vector<vector<int>>& cuboids) {
       
    //     for (auto& it : cuboids) { // first sort all the vectors indivisually
    //         sort(it.begin(), it.end());
    //     }
    //     sort(cuboids.begin(), cuboids.end());
    //     int curr = 0,prev = -1;
    //     int ans = SolveTabulation(cuboids, curr, prev);
    //     return ans;
    // }



    // optimization method

        bool issafe(vector<int> v1, vector<int> v2) {
        if (v1[0] <= v2[0] && v1[1] <= v2[1] && v1[2] <= v2[2])
            return true;
        return false;
    }

    int Optimization (vector<vector<int>>& cuboids, int curr,int prev) {
         int n=cuboids.size();
        vector<int>prevRow(n+1,0);
        vector<int>currRow(n+1,0);
 
        for(int curr=n-1;curr>=0;curr--){
             for(int prev=n-1;prev>=-1;prev--){
                int include = 0;
                if (prev == -1 || issafe(cuboids[prev], cuboids[curr])) {
                    include = cuboids[curr][2] + prevRow[curr+1];
                }
                int exclude = 0 + prevRow [prev+1];
                currRow[prev+1] = max(include, exclude);
             }
             prevRow=currRow; 
        }
      
        return prevRow[-1+1]; // ab yaha +1 kiya hai toh har right wale me +1
    }

    int maxHeight(vector<vector<int>>& cuboids) {
       
        for (auto& it : cuboids) { // first sort all the vectors indivisually
            sort(it.begin(), it.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int curr = 0,prev = -1;
        int ans = Optimization(cuboids, curr, prev);
        return ans;
    }
};
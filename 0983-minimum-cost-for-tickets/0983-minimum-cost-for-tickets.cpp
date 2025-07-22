class Solution {
public:
    // dp assingment
    ////////////// Brute force method  TLE
    // int solve(vector<int>& days, vector<int>& costs, int i) {
    //     // Base case: No more days left
    //     if (i >= days.size()) return 0;

    //     // Option 1: Buy 1-day pass & move to next day
    //     int cost1 = costs[0] + solve(days, costs, i + 1);

    //     // Option 2: Buy 7-day pass & skip covered days
    //     int passEndDay = days[i] + 7 - 1;
    //     int j = i;
    //     while (j < days.size() && days[j] <= passEndDay) j++;
    //     int cost7 = costs[1] + solve(days, costs, j);

    //     // Option 3: Buy 30-day pass & skip covered days
    //     passEndDay = days[i] + 30 - 1;
    //     j = i;
    //     while (j < days.size() && days[j] <= passEndDay) j++;
    //     int cost30 = costs[2] + solve(days, costs, j);

    //     // Return the minimum of all options
    //     return min(cost1, min(cost7, cost30));
    // }

    //     int mincostTickets(vector<int>& days, vector<int>& costs) {
    //         return solve(days, costs, 0);
    //     }

    /////////// memoization method / Dp method- 1

    int solve(vector<int>& days, vector<int>& costs, int i,  vector<int>&dp) {
        // Base case: No more days left
        if (i >= days.size())
            return 0;
        
        if(dp[i]!=-1) return dp[i];
        // Option 1: Buy 1-day pass & move to next day
        int cost1 = costs[0] + solve(days, costs, i + 1,dp);

        // Option 2: Buy 7-day pass & skip covered days
        int j = i;
        int passCoverDay = days[i] + 7 - 1;

        while (j<days.size() && days[j] <= passCoverDay) {
            j++;
        }
        int cost7 = costs[1] + solve(days, costs, j,dp);

        // Option 3: Buy 30-day pass & skip covered days
        int k = i;
         passCoverDay = days[i] + 30 - 1;

        while (k<days.size() && days[k] <= passCoverDay) {
            k++;
        }
        int cost30 = costs[2] + solve(days, costs, k,dp);
        // Return the minimum of all options


        dp[i]= min(cost30,min(cost1,cost7));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return solve(days,costs,0,dp);
    }

    // int solve(vector<int>& days, vector<int>& costs, int i,vector<int>&dp) {
    //     // Base case: No more days left
    //     if (i >= days.size()) return 0;

    //     if(dp[i]!=-1) return dp[i];

    //     // Option 1: Buy 1-day pass & move to next day
    //     int cost1 = costs[0] + solve(days, costs, i + 1,dp);

    //     // Option 2: Buy 7-day pass & skip covered days
    //     int passEndDay = days[i] + 7 - 1;
    //     int j = i;
    //     while (j < days.size() && days[j] <= passEndDay) j++;
    //     int cost7 = costs[1] + solve(days, costs, j,dp);

    //     // Option 3: Buy 30-day pass & skip covered days
    //     passEndDay = days[i] + 30 - 1;
    //     j = i;
    //     while (j < days.size() && days[j] <= passEndDay) j++;
    //     int cost30 = costs[2] + solve(days, costs, j,dp);

    //     // Return the minimum of all options
    //     return dp[i]=min(cost1, min(cost7, cost30));
    //     }
    //     int mincostTickets(vector<int>& days, vector<int>& costs) {
    //         vector<int>dp(days.size()+1,-1);
    //         return solve(days, costs, 0,dp);
    //     }
};
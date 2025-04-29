class Solution {
public:
    // solve using recursssion
    // LB DP-6  1:10:00

    // bool isSolve(string& s, string& p, int i, int j) {
    //     // basecase
    //     if (i == s.size() && j == p.size()) return true;
    //     if (i < s.size() && j == p.size())return false;

    //     bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

    //     // here we check if j+1 is within range and p[j+1] is "*"

    //     // Check if the next character in the pattern is '*', which means zero
    //     // or more of the preceding character
    //     if (j + 1 < p.size() && p[j + 1] == '*') {
    //         // Option 1: Skip the '*' and its preceding character (i.e., treat '*' as empty)
    //         bool x = isSolve(s, p, i, j + 2);

    //         // Option 2: Use '*' to match one or more of the preceding element (move the string forward by 1)
    //         bool y = match && isSolve(s, p, i + 1, j);
    //         return x || y;
    //     }

    //     if (match) {
    //         return isSolve(s, p, i + 1,j + 1); // Move both string and pattern forward
    //     }
    //     // no match
    //     return false;
    // }

    // bool isMatch(string s, string p) {
    //     int i = 0, j = 0;
    //     return isSolve(s, p, i, j);
    // }

///////////// solve using memoization (Dp -1)

    bool isSolve(string& s, string& p, int i, int j, vector<vector<int>>&dp) {
        // basecase
        if (i == s.size() && j == p.size()) return true;
        if (i < s.size() && j == p.size())return false;
        if(dp[i][j]!=-1)return dp[i][j];

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        bool ans;

        // here we check if j+1 is within range and p[j+1] is "*"

        // Check if the next character in the pattern is '*', which means zero
        // or more of the preceding character
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Option 1: Skip the '*' and its preceding character (i.e., treat '*' as empty)
            bool x = isSolve(s, p, i, j + 2,dp);

            // Option 2: Use '*' to match one or more of the preceding element (move the string forward by 1)
            bool y = match && isSolve(s, p, i + 1, j,dp);
            ans= x || y;
        }

        else if (match) {
            return isSolve(s, p, i + 1,j + 1,dp); // Move both string and pattern forward
        }
        // no match
      else {ans=false;}
        dp[i][j]=ans;
                return dp[i][j];
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int i = 0, j = 0;
        return isSolve(s, p, i, j,dp);
    }


};
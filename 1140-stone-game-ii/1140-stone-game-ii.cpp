class Solution {
public:
// Game Strategy
// yt -> https://youtu.be/9f1vzDFVnGA?si=NCIzvZPtYU6i4kgF
int solve(vector<int>& piles, int i, int m, bool alice,vector<vector<vector<int>>>& dp) {
    if (i == piles.size()) return 0;

    if(dp[i][m][alice]!=-1) return dp[i][m][alice];

    int ans = alice ? INT_MIN : INT_MAX; // Alice tries to maximize, Bob tries to minimize
    int total = 0;

    for (int x = 1; x <= 2 * m; x++) { // Condition according to the question
        if (i + x - 1 >= piles.size()) break;

        total += piles[i + x - 1];
        if (alice) {
            // Alice always wants to maximize her total stones
            ans = max(ans, total + solve(piles, i + x, max(x, m), !alice,dp));
        } else {
            // Bob always tries to minimize Alice's stones
            ans = min(ans, solve(piles, i + x, max(x, m), !alice,dp));
        }
    }
    dp[i][m][alice]=ans;
    return dp[i][m][alice];
}

int stoneGameII(vector<int>& piles) {
    bool alice = true;
    int n=piles.size()-1;
    vector<vector<vector<int>>> dp(n+2, vector<vector<int>>(n + 2, vector<int>(2, -1)));
    return solve(piles, 0, 1, alice,dp); // {piles, i, m, turn}
}
};
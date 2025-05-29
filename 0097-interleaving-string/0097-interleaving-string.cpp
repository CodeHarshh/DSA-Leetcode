class Solution {
public:


 bool solve(string &s1, string &s2, string &s3,int i , int j ,int k , vector<vector<vector<int>>>&dp){
    if(i==s1.size() && j==s2.size() && k==s3.size()) return true;
    
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    bool flag=false;

    if(i<s1.size() && s1[i]==s3[k]){
        flag= flag || solve(s1,s2,s3,i+1,j,k+1,dp);
    }

    if(j<s2.size() && s2[j]==s3[k]){
        flag= flag || solve(s1,s2,s3,i,j+1,k+1,dp);
    }
    dp[i][j][k]=flag;
    return dp[i][j][k];
 }
    bool isInterleave(string s1, string s2, string s3) {
        //       Continue matching with s1 as long as elements match.
        // When a difference is found, shift to s2 and start matching.
        // If a difference occurs in s2, return to matching with s1.
       vector<vector<vector<int>>>dp (s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return solve(s1,s2,s3,0,0,0,dp);

    }
};
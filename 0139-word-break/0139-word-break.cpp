class Solution {
public:

bool check(vector<string>& wordDict,string& s){
    for(auto it:wordDict){
        if(it==s) return true;
    }
    return false;
}

bool solve(string &s, vector<string>& wordDict,int start, vector<int>&dp){
    if(start==s.size())return true;
    
    if(dp[start]!=-1)return dp[start];
    string words="";
   
    for(int i=start;i<s.size();i++){  // here dont do i=0 because after each iteration the start shifts.
        words+=s[i];
        if(check(wordDict,words)){
             if(solve(s, wordDict, i + 1,dp)) {
                    return true;
                }
        }
        
    }
    dp[start]=false;
     return dp[start] ;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,-1);
        return solve(s,wordDict,0,dp);
    }
};
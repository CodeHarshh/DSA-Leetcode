class Solution {
public:
    // TLE

    bool solve(string &s,string &p,int si ,int pi){
        
        if(si==s.size()){
          while(pi!=p.size()){
            if(p[pi]!='*'){
                return false;
            }
            pi++;
          }            
          return true;
        }

        if(s[si]==p[pi] || p[pi]=='?') return solve(s,p,si+1,pi+1);

        if(p[pi]=='*'){
        
        bool case1= solve(s,p,si+1,pi);
        bool case2= solve(s,p,si,pi+1);

        return case1|| case2;

        }
        return false;
    }


      
    bool isMatch(string s, string p) {
       int si=0,pi=0;
      return  solve(s,p,si,pi);
    }





    // bool isMatchFun(string s, string p, int si, int pi) {
    //     // base case
    //     if (si == s.size() && pi == p.size())
    //         return true;
    //     if (si == s.size() && pi < p.size()) {
    //         while (pi != p.size()) {
    //             if (p[pi] != '*')
    //                 return false;
    //             pi++;
    //         }

    //         return true;
    //     }

    //     // matching single character
    //     if (s[si] == p[pi] || p[pi] == '?') {
    //         return isMatchFun(s, p, si + 1, pi + 1);
    //     }

    //     if (p[pi] == '*') {
    //         // Let * be treat as empty
    //         bool caseA = isMatchFun(s, p, si + 1, pi);
    //         // Let * matches 0 characters
    //         bool caseB = isMatchFun(s, p, si, pi + 1);

    //         return caseA || caseB;
    //     }
    //     return false;
    // }

    // bool isMatch(string s, string p) {
    //     int pi = 0; // index for p string
    //     int si = 0; // index for s string
    //     return isMatchFun(s, p, si, pi);
    // }












 ///// Dp Method 1 Memoization

    //     bool isMatchFun(string &s, string &p, int si, int pi, vector<vector<int>>&dp) {
          
    //          if(dp[si][pi]!=-1) return dp[si][pi];
    //            bool ans;
    //          if (si==s.size()  && pi==p.size()) ans= true; //string pattern both finished

    //         else if (si<s.size()  && pi==p.size()) ans= false;  // pattern finished but string still there
            

    //         else if (si==s.size()  && pi<p.size()){ // string finised but pattern was still there 
    //            while (pi < p.size() && p[pi] == '*') pi++; 
    //             ans = (pi == p.size());
 
    //         }
           

    //         else if (p[pi]==s[si] || p[pi]=='?'){
    //             ans= isMatchFun(s, p, si+1, pi+1,dp);
    //         }

    //         else if(p[pi]=='*'){
    //             // let treat * as empty
    //             bool x=isMatchFun(s, p, si, pi+1,dp);
    //             // let  * consume a character
    //             bool y=isMatchFun(s, p, si+1, pi,dp);
    //             ans=( x||y);
    //         }
    //         else{
    //              ans= false;
    //         }
    //       dp[si][pi]=ans;
    //   return dp[si][pi];
    // }

    // bool isMatch(string s, string p) {
    //     int pi = 0; // index for p string
    //     int si = 0; // index for s string
    //     int n=s.size();
    //     int m=p.size();
    //     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //     return isMatchFun(s, p, si, pi,dp);
    // }










//// solve using tabular method
    //       bool isMatchFun(string &s, string &p) {
    //         int n=s.size();
    //         int m=p.size();
    //         vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    //         dp[n][m]=true;

          
            
    //         bool ans;
    //          if (si==s.size()  && pi==p.size()) ans= true; //string pattern both finished

    //         else if (si<s.size()  && pi==p.size()) ans= false;  // pattern finished but string still there
            

    //         else if (si==s.size()  && pi<p.size()){ // string finised but pattern was still there 
    //            while (pi < p.size() && p[pi] == '*') pi++; 
    //             ans = (pi == p.size());
 
    //         }
           

    //         else if (p[pi]==s[si] || p[pi]=='?'){
    //             ans= isMatchFun(s, p, si+1, pi+1,dp);
    //         }

    //         else if(p[pi]=='*'){
    //             // let treat * as empty
    //             bool x=isMatchFun(s, p, si, pi+1,dp);
    //             // let  * consume a character
    //             bool y=isMatchFun(s, p, si+1, pi,dp);
    //             ans=( x||y);
    //         }
    //         else{
    //              ans= false;
    //         }
    //       dp[si][pi]=ans;
    //   return dp[si][pi];
    // }

    // bool isMatch(string s, string p) {
    //     int pi = 0; // index for p string
    //     int si = 0; // index for s string
       
    //     return isMatchFun(s, p);
    // }
};
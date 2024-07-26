class Solution {
public:

    void solve(string &output ,  vector<string>&ans, int open , int close,int n){
     if(open+close==2*n) {
        ans.push_back(output);
        return;
     }

     if(open<n){
        output.push_back('(');
        solve(output,ans,open+1,close,n) ;
        output.pop_back();
     }
     if(close<open){
          output.push_back(')');
        solve(output,ans,open,close+1,n);
         output.pop_back();
     }
    }
  
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output="";
        solve(output,ans,0,0, n);
        return ans;
    }
};
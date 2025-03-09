class Solution {
public:
   string removeDuplicates(string s) {
   string ans="";
  
   for(int i=0;i<s.size();i++){
     char current_elem=s[i];
    if(ans.empty()) ans.push_back(current_elem);
    else if (!ans.empty() && ans.back()==current_elem) ans.pop_back();
    else if (!ans.empty() && ans.back()!=current_elem) ans.push_back(current_elem);
   }
   return ans;
   }
};
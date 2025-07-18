class Solution {
public:
// https://youtu.be/SSdDVqrbfB8?si=m5ZtSqDTYJvN_1Dx

   static bool comp(string a , string b){
    return a+b > b+a;
       }


    string largestNumber(vector<int>& nums) {
        vector<string>v;

        for(int i=0;i<nums.size();i++){
            v.push_back(to_string(nums[i]));
        }

        sort(v.begin(),v.end(),comp);
        
        string ans="";

        for(auto it: v){
            ans = ans+ it ;   
            }

            if(ans[0]=='0') return "0";

          return ans;  

    }





    // static bool mycomp(string a, string b) {
    //     return a+b > b+a ;
    // }

    // string largestNumber(vector<int>& nums) {
    //     vector<string> s;
    //     for (auto i : nums) {
    //         s.push_back(to_string(i));
    //     }

    //     sort(s.begin(), s.end(), mycomp);
    //     string ans = "";

    //     for (auto i : s) {
    //         ans = ans + i;
    //     }
    //     if (ans[0] == '0')  return "0";
    //     return ans;
    // }
};
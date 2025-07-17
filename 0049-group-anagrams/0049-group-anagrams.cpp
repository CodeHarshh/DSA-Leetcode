class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(auto str:strs){
            string s=str;
            sort(s.begin(),s.end());
            m[s].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto it :m){
           ans.push_back(it.second);
    }
    return ans;
    }
};
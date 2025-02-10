class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>m;
         vector<string>ans;
        if(s.size()<10)return ans;
        for(int i=0;i<=s.size()-10;i++){
        string current=s.substr(i,10);
          m[current]++;
        }
        for(auto it:m){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        return ans;
    }
};
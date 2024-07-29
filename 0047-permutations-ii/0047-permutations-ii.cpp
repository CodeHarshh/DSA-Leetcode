class Solution {
public:

void solve(vector<int>& nums,vector<vector<int >>&v,int i){
    if(i>=nums.size()){
        v.push_back(nums);
        return;
    }

    for(int j=i;j<nums.size();j++){
    swap(nums[i],nums[j]);
    solve(nums,v,i+1);
      swap(nums[i],nums[j]);
    }

}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int >>v;
        solve(nums,v,0);

    
    set<vector<int>>s;
    for(auto it :v){
        s.insert(it);
    }
    v.clear();
    for(auto it:s){
   v.push_back(it);
    }
    return v;
}
};
class Solution {
public:
    // m1 ->o(n)^2
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> ans;
    //     for (int i = 0; i < nums.size()-1 ; i++) {
    //         for (int j = i+1; j < nums.size(); j++) {
    //             if (nums[i]+ nums[j] ==target ) {
    //                 ans.push_back(i);
    //                 ans.push_back(j);
    //                 return ans;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // m2 ->n(log)n

    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<pair<int, int>> ans; // value+index

    //     for (int i = 0; i < nums.size(); i++) {
    //         ans.push_back({nums[i], i});
    //     }
    //     sort(ans.begin(), ans.end());
    //     int i = 0, j = nums.size() - 1;
    //     while (i < j) {
    //         if (ans[i].first + ans[j].first == target)return {ans[i].second, ans[j].second};
    //         else if (ans[i].first + ans[j].first > target)j--;
    //         else if (ans[i].first + ans[j].first < target)i++;
    //     }
    //     return {-1, -1};
    // }




       vector<int> twoSum(vector<int>& nums, int target) {
      vector<pair<int,int>>v;
      for(int i=0;i<nums.size();i++){
        v.push_back({nums[i],i});
      }
      sort(v.begin(),v.end()); // -> tc: N log(N)
     int i=0,j=nums.size()-1;
     while(i<j){
        if(v[i].first+v[j].first==target){
            return{v[i].second,v[j].second};
        }
        else if(v[i].first+v[j].first>target){
           j--;
        }
          else if(v[i].first+v[j].first<target){
           i++;
        }
     }
  return {-1,-1};
    }
};
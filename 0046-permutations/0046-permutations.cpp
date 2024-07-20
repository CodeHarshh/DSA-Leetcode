class Solution {
public:
    void solve(vector<int>& nums, int i,  vector<vector<int>> &v) {

        if (i >= nums.size()){
            v.push_back(nums);
           return;  
        }
           
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            solve(nums, i + 1,v);
            // again swap due to back tracking
            swap(nums[i], nums[j]);
        }
    }

        vector<vector<int>> permute(vector<int> & nums) { 
            vector<vector<int>> v;
            solve(nums, 0,v); 
        return v;
        }
    };
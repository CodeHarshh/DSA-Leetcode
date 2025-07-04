class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(), ans=0;
        for(int i=0;i<n;i++){
            ans=ans^nums[i];
        }
        for(int i=0;i<=n;i++){
            ans=ans^i;
        }   
        return ans;     
    }
};
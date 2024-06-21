class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
 int n=nums.size()-1;
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1])  return nums[0];
           
        
        if(nums[n]!=nums[n-1]){
            return nums[n];
        }
        int s=1,e=n-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            if(mid%2 ==0 && nums[mid]==nums[mid-1] || mid%2 !=0 && nums[mid]==nums[mid+1]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return nums[mid];
    }
};

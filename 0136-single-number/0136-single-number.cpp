class Solution {
public:
// m=1
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int,int>m;
// int i=0;
//         while(i<nums.size()){
//             m[nums[i]]++;
//             i++;
//         }
//         i=0;
//         while(i<nums.size()){
//         if(m[nums[i]]==1){
//             return nums[i];
//         }
//           i++;
//         }
//         return -1;

// m2
 int singleNumber(vector<int>& nums) {
        int temp=0;
        for(int i=0;i<nums.size();i++){
         temp=temp^nums[i];
        }
     


        return temp;
        
    }
};
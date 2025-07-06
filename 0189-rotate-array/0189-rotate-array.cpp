
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() - 1;
       k = k % n ;
       
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
    }







    //        void rotate(vector<int>& nums, int k) {
    //         int n=nums.size();
    // k=k%n;
    // //first reverse all array
    // // then reverse till k
    // //then rev the rest array
    // reverse(nums.begin(),nums.end());
    //     reverse(nums.begin(),nums.begin()+k);
    //     reverse(nums.begin()+k,nums.end());
// }
}
;
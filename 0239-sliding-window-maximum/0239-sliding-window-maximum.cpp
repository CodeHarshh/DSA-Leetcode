class Solution {
public:
// TLE METHOD
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> maxi;

    //     for (int i = 0; i < nums.size(); i++) {
    //         int maxNum = INT_MIN;
    //         if(i+k<=nums.size()){
    //              for (int j = i; j <i+k; j++) {
    //             maxNum = max(maxNum, nums[j]);
    //         }
    //         maxi.push_back(maxNum);
    //         }
           
    //     }

    //     return maxi;
    // }



     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<nums.size();i++){
          while(!dq.empty()  && nums[dq.back()]< nums[i]){
            dq.pop_back();
          }

          dq.push_back(i);

          if(dq.front()+k==i){
            dq.pop_front();
          }
           // If we've processed at least k elements, add to result
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
        }
        return ans;
    }
};
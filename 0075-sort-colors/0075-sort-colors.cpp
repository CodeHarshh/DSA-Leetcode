// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int low = 0, mid = 0, high = nums.size() - 1;
        
//         while (mid <= high) {
//             if (nums[mid] == 0) {
//                 swap(nums[low], nums[mid]);
//                 low++;
//                 mid++;
//             } else if (nums[mid] == 1) {
//                 mid++;
//             } else { 
//                 swap(nums[mid], nums[high]);
//                 high--;
//             }
//         }
//     }
// };
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeroCount++;
            else if (nums[i] == 1) oneCount++;
            else twoCount++;
        }
        
        int index = 0;
        for (int i = 0; i < zeroCount; i++) {
            nums[index++] = 0;
        }
        for (int i = 0; i < oneCount; i++) {
            nums[index++] = 1;
        }
        for (int i = 0; i < twoCount; i++) {
            nums[index++] = 2;
        }
    }
};


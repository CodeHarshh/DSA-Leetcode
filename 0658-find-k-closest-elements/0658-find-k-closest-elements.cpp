class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       
        vector<int> ans;
        int low = 0, high = arr.size() - 1;

        while (high - low >= k) {
            if (abs(arr[low] - x) > abs(arr[high] - x)) {
                low++;
            } else if (abs(arr[low] - x) == abs(arr[high] - x)) {
                high--;
            } else {
                high--;
            }
        }
        while (low <= high) {
            ans.push_back(arr[low++]);
        }
        return ans;
    }
};
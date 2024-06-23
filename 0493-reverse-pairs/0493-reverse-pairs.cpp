class Solution {
public:
// extra function added in merge sort
    int countPair(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
      while (right <= high && (long long)arr[i] > 2 * (long long)arr[right]) {
                right++;
            }
            cnt = cnt + (right - (mid + 1));
        }
        return cnt;
    }



    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
              right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
               left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }  }



    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid =  low+(high-low)/2;
        // left part
        cnt = cnt + mergeSort(arr, low, mid);
        //right part
        cnt = cnt + mergeSort(arr, mid + 1, high);
        
        // now this will compare left and right and cnt 
        cnt = cnt + countPair(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }


    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
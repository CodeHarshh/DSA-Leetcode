class Solution {
public:
    void merge(vector<int>& nums, int s, int mid, int e) {
        int total_len = e - s + 1;
        int gap = (total_len / 2) + total_len % 2;
        while (gap > 0) {
            int i = s, j = s + gap;
            while (j <= e) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
                i++, j++;
            }
            if (gap <= 1) {
                gap = 0;
            } else {
                gap = (gap / 2) + gap % 2;
            }
        }
    }

    void mergesort(vector<int>& nums, int s, int e) {
        if (s >= e)
            return;
        int mid = s + (e - s) / 2;
        mergesort(nums, s, mid);
        mergesort(nums, mid + 1, e);
        merge(nums, s, mid, e);
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        mergesort(nums, s, e);
        return nums;
    }
};
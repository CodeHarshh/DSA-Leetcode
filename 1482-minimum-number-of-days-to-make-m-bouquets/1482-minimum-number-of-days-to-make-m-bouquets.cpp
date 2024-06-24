class Solution {
public:
    bool ispossible(vector<int>& bloomDay, int m, int k, int mid) {
        // mid=days
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                cnt++;
            }
            if (cnt == k) {
                cnt=0;
                m--;
                if (m == 0) {
                    return true;
                }
            }
            if (bloomDay[i] > mid) {
                cnt = 0;
            }
        }

        return m == 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int long long total_flower = (long long)m * (long long)k;
        if (total_flower > bloomDay.size())
            return -1;

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        int mid = s + (e - s) / 2;
        int ans = 0;
        while (s <= e) {

            if (ispossible(bloomDay, m, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }

        return ans;
    }
};
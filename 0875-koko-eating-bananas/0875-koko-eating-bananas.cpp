class Solution {
public:
    int long long totalhrsrequired(vector<int>& p, int k) {
        int long long total_cnt = 0;
        for (int i = 0; i < p.size(); i++) {
            total_cnt = total_cnt + p[i] / k;
            if (p[i] % k != 0) {
                total_cnt++;
            }
        }
        return total_cnt;
    }

    int minEatingSpeed(vector<int>& p, int h) {
        int s = 1;
        int e = *max_element(p.begin(), p.end());
        int mid = s + (e - s) / 2;
        int ans = 0;
        while (s <= e) {

            long long int totalhr = totalhrsrequired(p, mid);
// /If the total hours required is equal to the given hours h,
// the function should continue searching for a possibly smaller
            if (totalhr <= h) {
                e = mid - 1;
                ans = mid;
            } else {

                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};
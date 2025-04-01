class Solution {
public:
    int beautySum(string s) {
        // beauty= most frequent - least frequent
        int beauty_sum = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m.clear();
            for (int j = i; j < s.size(); j++) {

                m[s[j]]++;
                int mini = INT_MAX;
                int maxi = INT_MIN;

                for (auto k : m) {
                    if (k.second > 0) {
                        mini = min(mini, k.second);
                        maxi = max(maxi, k.second);
                    }}
                int beauty = maxi - mini;
                beauty_sum = beauty_sum + beauty;
            }
        }
        return beauty_sum;
    }
};
class Solution {
public:
    bool solve(vector<int>& arr, vector<int>& sides, int i) {
        if (i == arr.size()) {
            if (sides[0] == 0 && sides[1] == 0 && sides[2] == 0 &&
                sides[3] == 0) {
                return true;
            }
        }

        bool ans = false;

        for (int j = 0; j < sides.size(); j++) {

            if (arr[i] <= sides[j]) {
                sides[j] = sides[j] - arr[i];
                ans = ans || solve(arr, sides, i + 1);
                if (ans == true)
                    return true;

                sides[j] = sides[j] + arr[i];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& arr) {

        if (arr.size() < 4)
            return false;
        int n = arr.size();
        int totalsum = accumulate(arr.begin(), arr.end(), 0);

        if (totalsum % 4 != 0)
            return false;
        int SideSum = totalsum / 4;

        vector<int> sides(4, SideSum);
        // reverse sorting
        sort(arr.rbegin(), arr.rend());
        return solve(arr, sides, 0);
    }
};
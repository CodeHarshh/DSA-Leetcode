class Solution {
public:
    // https://youtu.be/JnxAWShm4PU?si=v0sRG_GOkJV5-hPG
    // string convert(string s, int numRows) {
    //     if (numRows <= 1)   return s;
    //     vector<string> Zigzag(numRows);
    //     int i = 0, row = 0;
    //     bool direction = 1;

    //     while (i < s.size()) {
    //         if (direction) {
    //             while (row < numRows && i < s.size()) {
    //                 Zigzag[row++].push_back(s[i++]);
    //             }
    //             row = numRows - 2;
    //         } else {
    //             while (row >= 0 && i < s.size()) {
    //                 Zigzag[row--].push_back(s[i++]);
    //             }
    //             row = 1;
    //         }
    //         direction = !direction;
    //     }
    //     string ans = "";
    //     for (int i = 0; i < Zigzag.size(); i++) {
    //         ans = ans + Zigzag[i];
    //     }
    //     return ans;
    // }

    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        vector<string> ans(numRows);
        bool flag = false;
        int i = 0;
        for (auto it : s) {
            ans[i] = ans[i] + it;

            if (i == 0 || i == numRows - 1) {
                flag = !flag;
            }

            if (flag) {
                i++;
            } else {
                i = i - 1;
            }
        }
        string zigzag="";
        for(auto it:ans){
            zigzag+=it;
        }
        return zigzag;
    }
};
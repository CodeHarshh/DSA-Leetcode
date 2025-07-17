class Solution {
public:
int maxLen=1 , start=0;

/// normal But better method 
    string expansion(string s, int i, int j) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        string longgest = "";

        for (int l = 0; l < s.size(); l++) {
            int i = l;
            int j = l;

            string p1 = expansion(s, i, j);
            if (p1.length() > longgest.length()) {
                longgest = p1;
            }
            i = l;
            j = l + 1;
            string p2 = expansion(s, i, j);
            if (p2.length() > longgest.length()) {
                longgest = p2;
            }
        }
        return longgest;
    }








///// normal But better method 
    // string expansion(string s, int i, int j) {
    //     while (i >= 0 && j < s.length() && s[i] == s[j]) {
    //         i--;
    //         j++;
    //     }
    //     return s.substr(i + 1, j - i - 1);
    // }
    // string longestPalindrome(string s) {
    //     if (s.empty())
    //         return "";
    //     string longgest = "";

    //     for (int l = 0; l < s.size(); l++) {
    //         int i = l;
    //         int j = l;

    //         string p1 = expansion(s, i, j);
    //         if (p1.length() > longgest.length()) {
    //             longgest = p1;
    //         }
    //         i = l;
    //         j = l + 1;
    //         string p2 = expansion(s, i, j);
    //         if (p2.length() > longgest.length()) {
    //             longgest = p2;
    //         }
    //     }
    //     return longgest;
    // }


/////// recurssion Dp mehtod-1

// bool solve(const string &s, int i, int j) {
//     if (i >= j) return true;

//     if (s[i] == s[j] && solve(s, i + 1, j - 1)) {
//         int currLen = j - i + 1;
//         if (currLen > maxLen) {
//             maxLen = currLen;
//             start = i;
//         }
//         return true;
//     }
//     return false;
// }

// string longestPalindrome(string s) {
//     int n = s.size();

//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             solve(s, i, j);
//         }
//     }

//     return s.substr(start, maxLen);
// }
};
class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());
        int left = 0, right = 0;
        int i = 0, n = s.size();

        while (i < n) {

            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i >= n) break;

            while (i < n && s[i] != ' ') {
                s[right] = s[i];
                i++;
                right++;
            }

            reverse(s.begin() + left, s.begin() + right);

            i++;
            s[right] = ' ';
            right++;
            left = right;
           
        }
         cout<<right;

        s.resize(right - 1);
        return s;
    }

    // string reverseWords(string s) {
    //     reverse(s.begin(), s.end());
    //     int left = 0, right = 0;
    //     int i = 0;
    //     int n = s.size();
    //     while (i < n) {

    //         while (i < n && s[i] == ' ') i++;

    //         if (i == n)
    //             break;

    //         while (i < n && s[i] != ' ') {
    //             s[right] = s[i];
    //             right++;
    //             i++;
    //         }
    //         reverse(s.begin() + left, s.begin() + right);
    //         // now add space after reverse
    //         s[right++] = ' ';
    //         left = right;
    //         i++;
    //     }
    //     s.resize(right - 1);
    //     return s;
    // }
};
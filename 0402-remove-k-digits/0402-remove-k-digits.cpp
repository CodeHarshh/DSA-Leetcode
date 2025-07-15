class Solution {
public:
    // keep smaller one from start
    // get rid from largest one from start

    // yt-> https://youtu.be/jmbuRzYPGrg?si=REf2GlMAhQjDl321

    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> st;

        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && num[i] < st.top() && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        if (k > 0) {             
            while (!st.empty() && k > 0) {
                st.pop();
                k--;
            }
        }

        while (!st.empty()) {
            ans = ans + st.top();
            st.pop();
        }

        while (ans.size() > 0 && ans.back() == '0') {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }

    // string removeKdigits(string num, int k) {
    //     string ans = "";
    //     stack<char> st;
    //     for (auto it : num) {
    //         while (!st.empty() && st.top() > it && k > 0) {
    //             st.pop();
    //             k--;
    //         }
    //         st.push(it);
    //     }

    //     if (k > 0) {
    //         while (k && !st.empty()) {
    //             st.pop();
    //             k--;
    //         }
    //     }
    //     while (!st.empty()) {
    //         ans.push_back(st.top());
    //         st.pop();
    //     }

    //     while (ans.size() > 0 &&
    //            ans.back() == '0') { // 200 after reverse 002 which is not
    //            vaild so remove it before reverse

    //         ans.pop_back();
    //     }
    //     if (ans.empty()) {
    //         return "0";
    //     }
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    // }
};
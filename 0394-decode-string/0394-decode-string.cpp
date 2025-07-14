class Solution {
public:
    ///*************

    // ✅ 3–4 Line Logic Summary of Full Code (decodeString):

    // Traverse the input string, pushing characters onto a stack.
    // When ] is found, pop to get the string inside [...] and the number before
    // it. Repeat the extracted string k times and push it back to the stack.
    // Finally, pop and join all parts from the stack to form the decoded
    // result.

    string decodeString(string s) {
        stack<string> st;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == ']') {
                string temp = "";
                while (!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                int digit = 0;
                string numStr = "";

                while (!st.empty() && isdigit(st.top()[0])) {
                    numStr = st.top() + numStr;
                    st.pop();
                }
                digit = stoi(numStr);

                string repeatedString = "";
                while (digit > 0) {
                    repeatedString += temp;
                    digit--;
                }

                st.push(repeatedString);
            } else {
                string str = string("") + ch;
                st.push(str);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }

    // string decodeString(string s) {
    //     stack<string> st;
    //     for (char it : s) {

    //         if (it == ']') {
    //             string temp = "";
    //             while (!st.empty() && st.top() != "[") {

    //                 temp = st.top() + temp;
    //                 st.pop();
    //             }
    //             if (!st.empty() && st.top() == "[") { // Pop the '['
    //                 st.pop();
    //             }

    //             string NumbericString = "";
    //             while (!st.empty() && isdigit(st.top()[0])) {
    //                 NumbericString = st.top() + NumbericString;
    //                 st.pop();
    //             }

    //             int cnt = 0;
    //             for (char c : NumbericString) {
    //                 if (isdigit(c)) {
    //                     cnt = cnt * 10 + (c - '0');
    //                 }
    //             }

    //             string repeatedString = "";
    //             for (int i = 0; i < cnt; i++) {
    //                 repeatedString = repeatedString + temp;
    //             }
    //             st.push(repeatedString);

    //         } else {
    //             string temp1 = string(1, it); // char converted into string
    //             st.push(temp1);
    //         }
    //     }

    //     string ans = "";
    //     while (!st.empty()) {
    //         ans = st.top() + ans;
    //         st.pop();
    //     }

    //     return ans;
    // }
};
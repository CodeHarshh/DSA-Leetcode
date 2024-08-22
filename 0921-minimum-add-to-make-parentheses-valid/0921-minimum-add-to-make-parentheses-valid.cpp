class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '{' || ch == '[' || ch == '(') {
                st.push(ch);
            } else {
                if (!st.empty() && ((ch == '}' && st.top() == '{') ||
                                    (ch == ']' && st.top() == '[') ||
                                    (ch == ')' && st.top() == '('))) {
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
        }

        int cnt = 0;
        while (!st.empty()) {
            st.pop();
            cnt++;
        }

        return cnt;
    }
};
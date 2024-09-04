class Solution {
public:
///*************
    string decodeString(string s) {
        stack<string> st;
        for (char it : s) {

            if (it == ']') {
                string temp = "";
                while (!st.empty() && st.top() != "[") {

                    temp = st.top() + temp;
                    st.pop();
                }
                if (!st.empty() && st.top() == "[") { // Pop the '['
                    st.pop();
                }

                string NumbericString = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    NumbericString = st.top() + NumbericString;// digit like 3 will come 
                    st.pop();
                }

                int cnt = 0;
                for (char c : NumbericString) {
                    if (isdigit(c)) {
                        cnt = cnt * 10 + (c - '0');
                    }
                }

                string repeatedString = "";
                for (int i = 0; i < cnt; i++) {
                    repeatedString = repeatedString + temp;
                }
                st.push(repeatedString);

            } else {
                string temp1 = string(1, it); // char converted into string
                st.push(temp1);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
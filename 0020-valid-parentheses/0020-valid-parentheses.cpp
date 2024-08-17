class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i];
            if (ch == '[' || ch == '(' || ch == '{') {
                st.push(ch);
            } else {
                if (!st.empty() && st.top() == '[' && ch == ']' ||
                   !st.empty() &&  st.top() == '{' && ch == '}' ||
                   !st.empty() &&  st.top() == '(' && ch == ')') {
                    st.pop();
                }
                else{
                     return false;
                } 
            }
}


        return st.empty();
    }
};
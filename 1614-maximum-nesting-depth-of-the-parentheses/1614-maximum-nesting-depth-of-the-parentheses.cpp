class Solution {
public:
    int maxDepth(string s) {
        int maxCnt = 0;
        stack<char> st;
        for (auto it : s) {
            if (it == '(') {
                st.push('(');
            } else if (it == ')') {
                if (st.size() > maxCnt)
                    maxCnt = st.size();
                st.pop();
            }
        }
        return maxCnt;
    }
};
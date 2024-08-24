class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        while (i < path.size()) {
            int start = i;
            int end = i + 1;
            while (end < path.size() && path[end] != '/') {
                end++;
            }
            string minpath = path.substr(start, end - start);
            i = end;
            if (minpath == "/" || minpath == "/.")
                continue;
            if (minpath != "/..")
                st.push(minpath);
            else if (minpath == "/.." && !st.empty())
                st.pop();
        }
        string ans = path.empty() ? "/" : "";
        while (!st.empty()) {
            ans =  st.top() + ans;
            st.pop();
        }

        return ans.empty()? "/":ans;
    }
};
class Solution {
public:
    bool isValid(string s) {
        if (s[0] == 'b' || s[0] == 'c')
            return false;

        stack<char> st;

        for (char ch : s) {
            if (ch == 'a') {
                st.push('a');
                 }
            else if (ch == 'b'){
                if (!st.empty() && st.top() == 'a') st.push('b');
                else return false;
            } else if (ch == 'c') { // it will be c
                if (!st.empty() && st.top() == 'b') {
                    st.pop();
                    if (!st.empty() && st.top() == 'a') {
                        st.pop();
                    } else
                        return false;
                } else
                    return false;
            }
        }
        return st.empty();
    }
    // m2
    // bool isValid(string s) {
    //     if(s.size()==0) return true;

    //     int find=s.find("abc");
    //     if(find!=string::npos){ //found
    //         string left=s.substr(0,find);
    //          string right=s.substr(find+3,s.size());
    //          return isValid(left+right);
    //     }
    //     return false;
    // }
};
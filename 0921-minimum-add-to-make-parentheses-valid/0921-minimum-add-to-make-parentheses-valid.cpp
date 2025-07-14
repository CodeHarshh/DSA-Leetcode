class Solution {
public:

// ✅ Logic Summary (3-4 lines):

// Use a stack to match opening and closing brackets.
// Push opening brackets directly.
// For closing brackets, pop if top matches; else push.
// Unmatched brackets left in stack = minimum insertions needed.

    int minAddToMakeValid(string s) {
        stack<char>st;

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='('){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top()=='(') st.pop();

                else st.push(ch);
            }
        }
        return st.size();
  
    }
};
class Solution {
public:
    bool isValid(string s) {
        if (s[0] == 'b' || s[0] == 'c')
            return false;

        stack<char> st;
        st.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            char ch=s[i];
            if(ch=='a') {st.push('a');}

            else if(!st.empty() && ch=='b' ){
                if(st.top()=='a'){
                     st.push('b');
                }else{
                    return false;
                }
               
            }
             else if(!st.empty() && ch=='c' ){
               if(st.top()=='b'){
                st.pop();
                if(st.top()=='a') st.pop();
                else return false;
               }
               else {return false;}
             }
        }
          

        return st.empty();
    }

    //   bool isValid(string s) {
    //     if (s[0] == 'b' || s[0] == 'c')
    //         return false;

    //     stack<char> st;

    //     for (char ch : s) {
    //         if (ch == 'a') {
    //             st.push('a');
    //              }
    //         else if (ch == 'b'){
    //             if (!st.empty() && st.top() == 'a') st.push('b');
    //             else return false;
    //         } else if (ch == 'c') { // it will be c
    //             if (!st.empty() && st.top() == 'b') {
    //                 st.pop();
    //                 if (!st.empty() && st.top() == 'a') {
    //                     st.pop();
    //                 } else
    //                     return false;
    //             } else
    //                 return false;
    //         }
    //     }
    //     return st.empty();
};
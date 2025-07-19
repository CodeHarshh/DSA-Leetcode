class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push({s[i], 1});
            } else {
                if (!st.empty() && s[i] == st.top().first) {
                    int cnt = st.top().second + 1;
                    st.pop();
                    st.push({s[i], cnt});

                    if (!st.empty() && st.top().second== k) {
                        st.pop();
                    }
                } else {
                    st.push({s[i], 1});
                }
            }
        }
        string ans = "";
        while (!st.empty()) {
            char ch=st.top().first;
            int no=st.top().second;
            while(no--){
                ans =ch+ans;
            }
            st.pop();
        }
        return ans;
    }

    // string removeDuplicates(string s, int k) {
    //     // M2
    //     stack < pair < char, int >> st;

    //     for (int i = 0; i < s.size(); i++) {
    //         if (st.empty())
    //             st.push({s[i], 1});
    //         else {
    //             if (st.top().first == s[i]) {
    //                 int c = st.top().second + 1;
    //                 st.pop();
    //                 st.push({s[i], c});
    //             } else {
    //                 st.push({s[i], 1});
    //             }
    //             if (!st.empty() && st.top().second == k) {
    //                 st.pop();
    //             }
    //         }
    //     }
    //     string ans = "";
    //     while(!st.empty()){
    //         char ch= st.top().first;
    //         int in=st.top().second;
    //         while(in--){
    //             ans.push_back(ch);
    //         }
    //         st.pop();
    //     }
    //     reverse(ans.begin(),ans.end());

    //     return ans;
    //      }

    // M1 (BUT MEMORY LIMIT EXCEEDED)
    // bool islastK_1same(char ch,string ans,int q ){
    //     int n=ans.size();
    //     for(int i=n-q;i<n;i++){
    //       if(ans[i]!=ch) return false;
    //     }
    //     return true;
    // }

    //     string removeDuplicates(string s, int k) {
    //         string ans="";
    //         for(int i=0;i<s.size();i++){
    //             char ch=s[i];
    //             if(ans.size()<k-1){
    //                 ans.push_back(ch);
    //             }
    //             else{
    //                 if(islastK_1same(ch,ans,k-1)){
    //                     int l=k-1;
    //                     while(l>0){
    //                         ans.pop_back();
    //                         l--;
    //                     }
    //                 }
    //                 else{
    //                     ans.push_back(ch);
    //                 }
    //             }
    //     }
    //     return ans;
    //     }
};
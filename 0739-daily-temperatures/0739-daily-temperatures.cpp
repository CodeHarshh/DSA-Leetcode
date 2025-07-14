class Solution {
public:
    // \U0001f539 Short Logic Summary

    // Use a stack to keep indices of temperatures in decreasing order.
    // For each day i, check if current temp is higher than the top of stack.
    // If yes, pop and calculate how many days it took to get a warmer day.
    // Push current day i onto the stack.

    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size(), 0);
        stack<int> st;

        for (int i = 0; i < temp.size(); i++) {

            while (!st.empty() && temp[i] > temp[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    // vector<int> dailyTemperatures(vector<int>& temp) {
    //     vector<int> ans(temp.size(), 0);
    //     stack<int> st;

    //     for (int i = 0; i < temp.size(); i++) {
    //         while (!st.empty() && temp[i] > temp[st.top()]) {
    //             ans[st.top()] = i - st.top();
    //             st.pop();
    //         }
    //         st.push(i);
    //     }
    //     return ans;
    // }
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }

        stack<int> st;
        vector<int> ans(v.size());
        for (int i = 0; i < v.size(); i++) {
            while (!st.empty() && v[i] > v[st.top()]) {
                int temp = st.top();
                st.pop();
                ans[temp] = v[i];
            }
            st.push(i);
        }
        return ans;
    }
};
class Solution {
public:
// -> https://youtu.be/If--3pm9K3U?si=6EXBvEi_p9bjl2C0
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<int> st;
        for (int i = 2*n-1; i >= 0; i--) { // we are traversing the same
            int curr= nums[i%n];           // array two times from left 
                while (!st.empty() && st.top() <= curr) {
                    st.pop();
                }
                if (st.empty()) {
                   ans[i%n]=-1;
                } else {
                   ans[i%n]=st.top();
                }
                st.push(nums[i%n]);
            }
            return ans;
        }
          
};
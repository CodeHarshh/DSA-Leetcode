class Solution {
public:
    // \U0001f504 Role of Each Array
    // Use nums2 to find the next greater element of each number.

    // Use nums1 to ask the query:
    // What's the next greater element of nums1[i] in nums2
   
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) {

                while (!st.empty() && st.top() <= nums2[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    m[nums2[i]] = -1;
                } else {
                    m[nums2[i]] = st.top();
                }
                st.push(nums2[i]);
            
        }
        vector<int> ans;

        for (auto it : nums1) {
            ans.push_back(m[it]);
        }
        return ans;
    }


    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_map<int, int> m;
    //     stack<int> st;
    //     for (int i = nums2.size() - 1; i >= 0; i--) {

    //         if (st.empty()) {
    //             m[nums2[i]] = -1;
    //             st.push(nums2[i]);
    //         } else {

    //             while (!st.empty() && st.top() <= nums2[i]) {
    //                 st.pop();
    //             }
    //             if (st.empty()) {
    //                 m[nums2[i]] = -1;
    //             } else {
    //                 m[nums2[i]] = st.top();
    //             }
    //             st.push(nums2[i]);
    //         }
    //     }
    //     vector<int> ans;

    //     for (auto it : nums1) {
    //         ans.push_back(m[it]);
    //     }
    //     return ans;
    // }
};
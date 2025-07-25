
class Solution {
public:
    // vector<int> nextLargerNodes(ListNode* head) {
    //     vector<int> v;
    //     while (head) {
    //         v.push_back(head->val);
    //         head = head->next;
    //     }

    //     stack<int> st;
    //     vector<int> ans(v.size());
    //     for (int i = 0; i < v.size(); i++) {
    //         while (!st.empty() && v[i] > v[st.top()]) {
    //             int temp = st.top();
    //             st.pop();
    //             ans[temp] = v[i];
    //         }
    //         st.push(i);
    //     }
    //     return ans;
    // }


    vector<int> nextLargerNodes(ListNode* head) {
       vector<int>v;
       ListNode* temp=head;
       stack<int>st;
       

       while(temp!=NULL){
        v.push_back(temp->val);
        temp=temp->next;
       }
       vector<int>ans(v.size(),0);

       for(int i=v.size()-1;i>=0;i--){
       
            while(!st.empty() && st.top()<=v[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=st.top();
            }
         st.push(v[i]);
       
       }
       return ans;
    }
};
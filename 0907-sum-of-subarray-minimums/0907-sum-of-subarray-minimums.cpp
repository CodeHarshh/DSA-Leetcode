class Solution {
public:
const int mod=1e9 +7;

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>left(n,0);
        vector<int>right(n,0);

        // find right smallest element 
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) right[i]=n;
            else right[i]=st.top();
            st.push(i);

        }         
        
        while(!st.empty()) st.pop();

        // find left smallest element
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) left[i]=-1;
            else left[i]=st.top();
            st.push(i);
        }  

       long long sum=0;
        // now check how many time's each number contibute in minimum
        for(int i=0;i<n;i++){
           long long rightSize= right[i] - i; 
           long long leftSize= i - left[i];
  sum = (sum + (arr[i] * leftSize % mod) * rightSize % mod) % mod;   
       }

        return (int) sum;

    }
};
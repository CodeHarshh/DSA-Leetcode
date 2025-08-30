// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         vector<int> ans;
//         unordered_map<int, int> m;
//         for (int i = 0; i < nums.size(); i++) {
//             m[nums[i]]++;
//         }

//         priority_queue<pair<int, int>, vector<pair<int, int>>,
//                        greater<pair<int, int>>>pq;
//         for (auto it : m) {
//             // {freq,number}
//             pq.push({it.second, it.first});
//             if (pq.size() > k) {
//                 pq.pop();
//                } 
//             }
//         for (int i = 0; i < k; i++) {
//             auto temp = pq.top();
//             cout<<temp.second<<" ";
//             pq.pop();
//             ans.push_back(temp.second);
//         }

//         for(auto it:ans){
//             // cout<<it<<" ";
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       vector<int>ans;
       unordered_map<int,int>m;
       
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

       for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
       }

       for(auto it:m){//{freq,number}
        pq.push({it.second,it.first});
        if(pq.size()>k){
            auto front=pq.top();
            pq.pop();
        }
       }

      while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
       
       return ans;
    }
};
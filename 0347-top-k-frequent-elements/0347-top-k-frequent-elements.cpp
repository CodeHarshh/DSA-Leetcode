class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        priority_queue<pair<int, int>>pq;


//, vector<pair<int, int>>, greater<pair<int, int>>
        for (auto it : m) {
            // {freq,number}
            pq.push({it.second, it.first});
        }

        for (int i = 0; i < k;i++) {
            auto temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }

        return ans;
    }
};
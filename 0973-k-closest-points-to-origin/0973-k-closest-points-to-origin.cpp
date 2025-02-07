class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    vector<vector<int>> ans;

      for(auto it:points ){
        int distanceSquare = it[0] * it[0] + it[1] * it[1];
        pq.push({distanceSquare ,it});
      }

    for(int i=0;i<k;i++){
        auto top=pq.top();
      ans.push_back(top.second);
      pq.pop();
    }
    return ans;
   
    }
};
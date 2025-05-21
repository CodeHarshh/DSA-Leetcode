class Solution {
public:
    bool topologicalSortDFS(vector<vector<int>>& adj, int n) {
        unordered_map<int, int> indegree;

        for (int i = 0; i < n; i++) {
            indegree[i] = 0;
        }

        // calculate indegree
        for (int i = 0; i < n; i++) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        for (auto it : indegree) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }
        vector<int> toposort;

        while (!q.empty()) {
            int front = q.front();

            q.pop();
            toposort.push_back(front);

            for (auto it : adj[front]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if (toposort.size() == n)
            return true;

        return false;
    }
    // is valid  topological sort
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for (auto it : prerequisites) {
            //   adj[it[0]].push_back(it[1]); XXXXX (because prerequisites imply course B depends on course A)
            adj[it[1]].push_back(it[0]);
        }
        bool ans = topologicalSortDFS(adj, n);
        return ans;
    }
};
class Solution {
public:
    vector<int> dijkstra(int V, unordered_map<int, list<pair<int, int>>>& adjList, int src, int distanceThreshold) {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> st; // (distance, node)

        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto topElement = st.begin();
            int topNodeDistance = topElement->first;
            int topNode = topElement->second;
            st.erase(topElement);

            for (auto& neighbour : adjList[topNode]) {
                int neighborNode = neighbour.first;
                int weight = neighbour.second;

                if (dist[topNode] + weight < dist[neighborNode]) {
                    auto it = st.find({dist[neighborNode], neighborNode});
                    if (it != st.end()) {
                        st.erase(it);
                    }

                    dist[neighborNode] = dist[topNode] + weight;
                    st.insert({dist[neighborNode], neighborNode});
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] > distanceThreshold) {
                dist[i] = -1;
            }
        }

        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, list<pair<int, int>>> adjList;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        int cityWithFewestNeighbors = -1;
        int fewestNeighbors = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> distances = dijkstra(n, adjList, i, distanceThreshold);

            int reachableCities = 0;
            for (int dist : distances) {
                if (dist != -1) { // Only count valid nodes within the threshold
                    reachableCities++;
                }
            }

            if (reachableCities <= fewestNeighbors) {
                fewestNeighbors = reachableCities;
                cityWithFewestNeighbors = i;
            }
        }

        return cityWithFewestNeighbors;
    }
};

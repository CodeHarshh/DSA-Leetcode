class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for (auto it : tasks) {
            m[it]++;
        }

        priority_queue<int> pq;
        for (auto it : m) {
            pq.push(it.second);
        }

        int time = 0;

        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> temp;

            while (cycle > 0 && !pq.empty()) {
                int freq = pq.top();
                pq.pop();
                freq--;
                if (freq > 0) {
                    temp.push_back(freq);
                }
                time++;
                cycle--;
            }

            for (int freq : temp) {
                pq.push(freq);
            }

            if (!pq.empty()) {
                time += cycle;
            }
        }

        return time;
    }
};

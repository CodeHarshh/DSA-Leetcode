class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {}

    int ping(int t) {
        q.push(t);

        // check valid range and removing the element not in range
        while (!q.empty()&& q.front() < (t - 3000)) {
            q.pop();

           
        }
         return q.size();
    }
    
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
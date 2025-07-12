class MinStack {
public:
    stack<pair<int, int>> st; // val,smallest
    MinStack() {}             // initializes the stack object.

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            if (st.top().second > val) {
                st.push({val, val});
            } else {
                st.push({val, st.top().second});
            }
        }
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

class Solution {
public:
    void nextSmallest(vector<int>& arr, vector<int>& nextAns) {
        stack<int> s;
        s.push(-1);
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            int elem = arr[i];

            while (s.top() != -1 && arr[s.top()] >= elem) {
                s.pop();
            }
            nextAns.push_back(s.top());
            s.push(i);
        }
    }

    void prevSmallest(vector<int>& arr, vector<int>& prevAns) {
        stack<int> s;
        s.push(-1);
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int elem = arr[i];

            while (s.top() != -1 && arr[s.top()] >=elem) {
                s.pop();
            }
            prevAns.push_back(s.top());
            s.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevAns;
        vector<int> nextAns;

        nextSmallest(heights, nextAns);
        // we have to revese the ans bcoz we havew used the stack
        reverse(nextAns.begin(), nextAns.end());
        for (int i = 0; i < nextAns.size(); i++) {
            if (nextAns[i] == -1)
                nextAns[i] = nextAns.size();
        }
        prevSmallest(heights, prevAns);

        vector<int> area;
        for (int i = 0; i < nextAns.size(); i++) {
            int width = nextAns[i] - prevAns[i] - 1;
            int height = heights[i];
            int currarea = width * height;
            area.push_back(currarea);
        }
        int max_area = INT_MIN;
        for (int i = 0; i < area.size(); i++) {
            max_area = max(max_area, area[i]);
        }
        return max_area;
    }
};
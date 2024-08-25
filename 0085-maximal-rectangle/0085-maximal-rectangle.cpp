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

            while (s.top() != -1 && arr[s.top()] >= elem) {
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
        // we have to revese the ans bcoz we have used the stack
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

    // all above code is same as largest histograph (leetcode -84)
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                temp.push_back(matrix[i][j] - '0');
            }
            v.push_back(temp);
        }

        int area = largestRectangleArea(v[0]);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] != 0) {
                    v[i][j] = v[i][j] + v[i - 1][j];
                } else {
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};
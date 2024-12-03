class Solution {
public:
    queue<int> q;
    int counter = 1;
    int findTheWinner(int n, int k) {
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        while (q.size() != 1) {
            if (counter == k) {
                q.pop();
                counter = 1;
            } else {
                int front = q.front();
                q.pop();
                q.push(front);
                counter++;
            }
        }
        return (q.front());
    }
};
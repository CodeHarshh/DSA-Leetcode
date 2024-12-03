class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {

        int curr = 0; // curr active spreader
        int ans = 1;  // atleast 1 person knows the secret
        int M =1e9 + 7;

        queue<pair<int, int>> delayQ, forgetQ; // <uss din  , Kitne longo ko secret pata hai>
        delayQ.push({1, 1});
        forgetQ.push({1, 1});

        for (int i = 1; i <= n; i++) {
            if (!forgetQ.empty() && forgetQ.front().first + forget <= i) {
                auto front = forgetQ.front();
                forgetQ.pop();
                auto num = front.second;
                ans = (ans - num +M) % M ;
                curr = (curr - num+ M )%M;
            }

            if (!delayQ.empty() && delayQ.front().first + delay <= i) {
                auto front = delayQ.front();
                delayQ.pop();
                curr = (curr + front.second)%M; // active ppl
            }

            if (curr > 0) {
                ans = (ans + curr) % M;
                delayQ.push({i, curr});
                forgetQ.push({i, curr});
            }
        }

        return ans;
    }
};
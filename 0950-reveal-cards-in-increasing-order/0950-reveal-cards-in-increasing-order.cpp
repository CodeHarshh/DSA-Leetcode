class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        vector<int> ans(deck.size());

        for (int i = 0; i < ans.size(); i++) {
            q.push(i);
        }

        for (int i = 0; i < deck.size(); i++) {
            if (!q.empty()) {
                ans[q.front()] = deck[i];
                q.pop();
            }
            if (!q.empty()) {
                int front = q.front();
                q.pop();
                q.push(front);
            }
        }
        return ans;
    }
};
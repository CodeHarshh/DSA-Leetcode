class Solution {
public:
    vector<string> ans;

    bool check(vector<string>& wordDict, string& s) {
        for (auto it : wordDict) {
            if (it == s) return true;
        }
        return false;
    }

    void solve(string &s, vector<string>& wordDict, int start, string temp) {
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }

        string word = "";

        for (int i = start; i < s.size(); i++) {
            word += s[i];
            if (check(wordDict, word)) {
                string newTemp = temp.empty() ? word : temp + " " + word;
                solve(s, wordDict, i + 1, newTemp);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ans.clear();
        solve(s, wordDict, 0, "");
        return ans;
    }
};

class Solution {
public:
    void solve(string& output, string digits, unordered_map<char, string> m,
               vector<string>& ans, int i) {
        if (i >= digits.size()) {
            ans.push_back(output);
            return;
        }

        char digit = digits[i];
        string MappedString = m[digit];

        for (char ch : MappedString) {
            output.push_back(ch);
            solve(output, digits, m, ans, i + 1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        int i = 0;
        if (digits.size() == 0)
            return ans;
        string output = "";
        solve(output, digits, m, ans, i);
        return ans;
    }
};
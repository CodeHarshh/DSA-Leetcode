class Solution {
public:
    void normalisation(string& s) {
        char start = 'a';
        unordered_map<char, char> m;
        for (int i = 0; i < s.size(); i++) {
            char currWord = s[i];
            if (m.find(currWord) == m.end()) {
                m[currWord] = start;
                start++;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            char mapppedchar = m[s[i]];
            s[i] = mapppedchar;
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words,string pattern) {
        vector<string> ans;
        normalisation(pattern);
        for (int i = 0; i < words.size(); i++) {
            string currword = words[i];
            string currwordcpy = currword;
            normalisation(currwordcpy);
            if (currwordcpy == pattern) {
                ans.push_back(currword);
            }
        }
        return ans;
    }
};
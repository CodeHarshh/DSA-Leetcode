class Solution {
public:
    string minWindow(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();

        if (l1 < l2)
            return "";

        int ansIndx = -1, ansLen = INT_MAX;

        unordered_map<char, int> Smap, Tmap;

        for (auto i : t)
            Tmap[i]++;

        int st = 0, e = 0, cnt = 0;

        while (e < l1) {
            char ch = s[e];
            Smap[ch]++;

            if (Smap[ch] <= Tmap[ch])
                cnt++;

            while (cnt == l2) {
                if (e - st + 1 < ansLen) {
                    ansLen = e - st + 1;
                    ansIndx = st;
                }
                char leftChar = s[st];
                Smap[leftChar]--;
                if (Smap[leftChar] < Tmap[leftChar])
                    cnt--;
                st++;
            }
            e++;
        }

        return ansIndx == -1 ? "" : s.substr(ansIndx, ansLen);
    }
};

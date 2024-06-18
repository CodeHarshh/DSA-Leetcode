class Solution {
public:
    int func(string x) {
        int c = 0;
        for (auto i : x) {
            c = c + (i - '0');
        }
        return c;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for (auto i : bank) {
            v.push_back(func(i));
        }
        int noOfBean = 0;
        for (int i = 0; i < v.size(); i++) {
            int j = i + 1;
            while (j < v.size()) {
                if (v[j] == 0)
                    j++;
                else {
                    noOfBean = noOfBean + (v[i] * v[j]);
                    break;
                }
            }
        }
        return noOfBean;
    }
};
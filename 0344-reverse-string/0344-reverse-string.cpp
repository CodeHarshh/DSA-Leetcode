class Solution {
public:
    void isSolve(vector<char>& s, int st, int e) {
        if (st > e) {
            return;
        }
        swap(s[st], s[e]);
        isSolve(s, st + 1, e - 1);
    }
    void reverseString(vector<char>& s) {

        // M1
        // reverse(s.begin(),s.end());

        // M2 (Recursion)

        int st = 0;
        int e = s.size();

        isSolve(s, st, e-1);

    }
};
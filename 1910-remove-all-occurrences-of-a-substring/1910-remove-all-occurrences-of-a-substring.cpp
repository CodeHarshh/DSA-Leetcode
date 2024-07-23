class Solution {
public:
    void solve(string& s, string& part) {

        if (s.find(part) == -1) {
            return;
        }
        if (s.find(part) != -1) {
            s.erase(s.find(part), part.length());
        }

        solve(s, part);
    }

    string removeOccurrences(string s, string part) {

        // m1
        //  while(s.find(part)!=-1){
        //    s.erase(s.find(part),part.length());
        //  }
        //  return s;

        solve(s, part);
        return s;
    }
};
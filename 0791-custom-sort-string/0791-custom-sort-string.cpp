string ordercopy;
class Solution {
public:
    //  if a character x occurs before a character y in order,
    // then x should occur before y in the permuted string.

    // static bool cmp(char a, char b) {
    //     return (ordercopy.find(a) < ordercopy.find(b));
    // }
    // string customSortString(string order, string s) {
    //     ordercopy = order;
    //     sort(s.begin(), s.end(), cmp);
    //     return s;
    // }

    static bool cmp(char a,char b){
        return (ordercopy.find(a) < ordercopy.find(b));
    }
    
    string customSortString(string order, string s){
        ordercopy=order;
        sort(s.begin(),s.end(),cmp);
        return s;
    }
   
};
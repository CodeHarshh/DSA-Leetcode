class Solution {
public:
    int solve(int n) {
     int cnt=0;
     while(n>0){
        int bit=n%2;
        if(bit==1)cnt++;
        n=n/2;
     }

     return cnt;
    }

    vector<int> countBits(int n) {
       vector<int>ans;
       for(int i=0;i<=n;i++){
        int rizz=solve(i);
        ans.push_back(rizz);
       }
       return ans;
    }









    // int solve(int n) {
    //     int cnt = 0;
    //     while (n > 0) {
    //         int bit = n % 2;
    //         if (bit == 1)
    //             cnt++;
    //         n = n / 2;
    //     }
    //     return cnt;
    // }

    // vector<int> countBits(int n) {
    //     vector<int> ans;
    //     for (int i = 0; i <= n; i++) {
    //         int solve_ans = solve(i);
    //         ans.push_back(solve_ans);
    //     }
    //     return ans;
    // }
};
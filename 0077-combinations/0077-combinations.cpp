class Solution {
public:

void solve(int n, int k, int st, vector<int>& curr,
               vector<vector<int>>& ans) {
        if(k==0){
           ans.push_back(curr);
           return;
        }   

        for(int i=st;i<=n;i++){
            curr.push_back(i);
            solve(n,k-1,i+1,curr,ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>>ans;
      vector<int>curr;
      solve(n,k,1,curr,ans);
      return ans;
    }



    // void solve(int n, int k, int st, vector<int>& curr,
    //            vector<vector<int>>& ans) {
    //     if (k == 0) {
    //         ans.push_back(curr);
    //         return;
    //     }

    //     for (int i = st; i <= n; i++) {
    //         curr.push_back(i);
    //         solve(n, k - 1, i + 1, curr, ans);
    //         curr.pop_back();
    //     }
    // }

    // vector<vector<int>> combine(int n, int k) {
    //     vector<vector<int>> ans;
    //     vector<int> curr;

    //     solve(n, k, 1, curr, ans);
    //     return ans;
    // }
};



// solve(4, 2, 1, [], ans)
// │
// ├─ push 1 → curr = [1]
// │   └─ solve(4, 1, 2, [1], ans)
// │       ├─ push 2 → curr = [1,2]
// │       │   └─ k == 0 → push to ans: [1,2]
// │       │   ← pop 2 → curr = [1]        ← BACKTRACK
// │       ├─ push 3 → curr = [1,3]
// │       │   └─ k == 0 → push to ans: [1,3]
// │       │   ← pop 3 → curr = [1]        ← BACKTRACK
// │       ├─ push 4 → curr = [1,4]
// │       │   └─ k == 0 → push to ans: [1,4]
// │       │   ← pop 4 → curr = [1]        ← BACKTRACK
// │   ← pop 1 → curr = []                 ← BACKTRACK
// │
// ├─ push 2 → curr = [2]
// │   └─ solve(4, 1, 3, [2], ans)
// │       ├─ push 3 → curr = [2,3]
// │       │   └─ push to ans: [2,3]
// │       │   ← pop 3 → curr = [2]        ← BACKTRACK
// │       ├─ push 4 → curr = [2,4]
// │       │   └─ push to ans: [2,4]
// │       │   ← pop 4 → curr = [2]        ← BACKTRACK
// │   ← pop 2 → curr = []                 ← BACKTRACK
// │
// ├─ push 3 → curr = [3]
// │   └─ solve(4, 1, 4, [3], ans)
// │       ├─ push 4 → curr = [3,4]
// │       │   └─ push to ans: [3,4]
// │       │   ← pop 4 → curr = [3]        ← BACKTRACK
// │   ← pop 3 → curr = []                 ← BACKTRACK
// │
// ├─ push 4 → curr = [4]
// │   └─ solve(4, 1, 5, [4], ans) → loop ends (i > n)
// │   ← pop 4 → curr = []                 ← BACKTRACK

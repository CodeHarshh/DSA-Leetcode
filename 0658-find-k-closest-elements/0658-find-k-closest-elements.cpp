class Solution {
public:

 vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int>ans;

        int l=0,h=arr.size()-1;

        while(h-l>=k){
        
        if(abs(arr[l]-x) > abs(arr[h]-x)){
            l++;
        }
        else  if(abs(arr[l]-x) < abs(arr[h]-x)){
            h--;
        }
        else  if(abs(arr[l]-x) == abs(arr[h]-x)){
            h--;
        }
        }

        for(int i=l;i<=h;i++){
            ans.push_back(arr[i]);
        }


        return ans;

    }












    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //     // ans vector
    //     // low = 0 & high = arr.size() - 1;
    //     // while (high - low >= k) {
    //     // if  (abs(arr[low] - x) > abs(arr[high] - x)) low++
    //     // and high-- in all other case
    //     // now push_back from i to j
    //     vector<int> ans;
    //     int low = 0, high = arr.size() - 1;

    //     while (high - low >= k) { //check if aleast k element is present or not
    //         if (abs(arr[low] - x) > abs(arr[high] - x)) {
    //             low++;
    //         } else if (abs(arr[low] - x) == abs(arr[high] - x)) {
    //             high--;
    //         } else {
    //             high--;
    //         }
    //     }
    //     while (low <= high) {
    //         ans.push_back(arr[low++]);
    //     }
    //     return ans;
    // }
};
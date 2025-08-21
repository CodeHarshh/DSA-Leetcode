class Solution {
public:
//sort

// set<pair<int, int>> s;
//i=0 ; j=1;
// while j<nums.size()
// dif=abs(nums[i] - nums[j]);
//  if (diff == k) insert in s |, if (diff < k)j++ |(diff >k) i++ | i==j then j++
// return s.size()

    int findPairs(vector<int>& nums, int k) {

       sort(nums.begin(),nums.end());
       set<pair<int,int>>st;
       int i=0,j=1;

       while( j<nums.size()){

       int diff=abs(nums[i]-nums[j]);
       if(diff==k) {st.insert({nums[i],nums[j]});
       i++,j++;
       }
       else if(diff<k) j++;
       else  if(diff>k)i++;
       if (i==j) j++;
       }
       return st.size();
    }
};

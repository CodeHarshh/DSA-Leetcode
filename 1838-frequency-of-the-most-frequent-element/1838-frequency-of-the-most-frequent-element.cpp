class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int long long maxfreq=0,l=0,r=0,n=nums.size(),total=0;

        for(r=0;r<n;r++){
            total=total+nums[r];

            while(l+1<=r && nums[r]*(r-l+1) > total+k){
                total=total-nums[l];
                l++;

            }
            maxfreq=max(maxfreq,(r-l+1));

        }
        return maxfreq;
    }
};
class Solution {
public:

bool ispossible(vector<int>& nums, int n, int k,int mid){
    int long std_cnt=1;
    int  long pagesum=0;

    for(int i=0;i<n;i++){
        if(pagesum+nums[i]<=mid){
            pagesum=pagesum+nums[i];
        }
        else{
            std_cnt++;
            if(std_cnt>k   || nums[i]>mid){
return false;
            }
            pagesum=nums[i];
        }
    }
return true;
}

    int splitArray(vector<int>& nums, int k) {
int n=nums.size();
   int long sum=0;
   int long s=0;

   for(int i=0;i<n;i++){
       sum=sum+nums[i];
   }

int long e= (int long)sum;
int  long mid =e/2;
int long  ans=-1;
while(s<=e){

if(ispossible(nums,n,k,mid)){
    e=mid-1;
}
else{
    s=mid+1;
}

mid=s+(e-s)/2;
}
return mid;
    }

    
};
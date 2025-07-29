class Solution {
public:
    // https://youtu.be/UHHp8USwx4M?si=TBIYSelC5CBYxjEM

     int trap(vector<int>& h) {
      int l = 0, r = h.size() - 1, ans = 0;
          
      vector<int>lmax(h.size(),0);
      vector<int>rmax(h.size(),0);

      lmax[0]=h[0];
      for(int i=1;i<=r;i++){
      lmax[i]=max(lmax[i-1],h[i]);
      }
    
      rmax[r]=h[r];
      for(int i=r-1;i>=0;i--){
      rmax[i]=max(h[i],rmax[i+1]);
      }

      while(l<r){
      ans+= min(lmax[l],rmax[l])-h[l];
      l++;
    }
    return ans;
     }
};
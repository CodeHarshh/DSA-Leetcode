class Solution {
public:
    int reverse(int x) {
         int ans = 0;
         while(x!=0){
            if(ans >INT_MAX/10 || ans <INT_MIN/10) return 0;
            int bit=x%10;
            ans=(ans*10)+bit;
            x=x/10;
         }
    return ans;
    
     }
};
class Solution {
public:
     int expandAroudCenter(string s,int i,int j){
        int cnt=0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
     }  
   
    int countSubstrings(string s) {
        int total=0;

        for(int l=0;l<s.length();l++){
            int i=l;
            int j=l;
            int oddplaindrome=expandAroudCenter(s,i,j);
            
            i=l;
            j=l+1;
             int evenplaindrome=expandAroudCenter(s,i,j);

             total=total+oddplaindrome+evenplaindrome;
        }
        return total;
    }
    
};
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.size()-1;

        while(i<j){
            if(!isalpha(s[i])){
                i++;
            }
         else  if(!isalpha(s[j])){
                j--;
            }
            else{
swap(s[i],s[j]);
            i++;
            j--;
            }
        //     if(s[i]=='_' ){
        //       i++;
        //     }
        //                 if(s[j]=='_' ){
        //       j--;
        //     }
               if(isalpha(s[i]) && isalpha(s[j])){
            
               }
        }
          return s;
    }
      
};
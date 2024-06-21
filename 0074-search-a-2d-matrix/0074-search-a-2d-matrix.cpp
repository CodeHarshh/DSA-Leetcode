class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int row=m.size();
        int col=m[0].size();
        int s=0;
        int e= (row*col)-1;
         int mid=s+(e-s)/2;
        
        while(s<=e){

            int rowindex=mid/col;
            int colindex=mid%col;
            
            if(m[rowindex][colindex]==target){
                return true;
            }
            else if(m[rowindex][colindex]<target){
                  s=mid+1;
            }
         else if(m[rowindex][colindex]>target){
                   e=mid-1;   
                    
        }
        mid=s+(e-s)/2;
                    
                    }
                    return false;
                    }
    
};
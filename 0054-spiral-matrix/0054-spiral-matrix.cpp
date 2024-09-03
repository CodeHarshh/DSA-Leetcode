class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int total=m*n;

    int StartingColumn=0;
    int EndingColumn=n-1;
       int EndingRow=m-1;
    int StartingRow=0;

int cnt=0;

while(cnt<total){

for(int i=StartingColumn;i<=EndingColumn  && cnt<total;i++){
    ans.push_back(matrix[StartingRow][i]);
cnt++;


}
StartingRow++;

for(int i=StartingRow;i<=EndingRow  && cnt<total;i++){
     ans.push_back(matrix[i][EndingColumn]);
 cnt++;
}
EndingColumn--;

for(int i=EndingColumn;i>=StartingColumn  && cnt<total;i--){
     ans.push_back(matrix[EndingRow][i]);
  cnt++;
}
EndingRow--;

for(int i=EndingRow;i>=StartingRow  && cnt<total ;i--){
     ans.push_back(matrix[i][StartingColumn]);
 cnt++;
}
StartingColumn++;

    }
return ans;
    }
};
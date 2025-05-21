class Solution {
public:
// lb  graph Lec 7
    int minimumEffortPath(vector<vector<int>>& height) {

      // min->heap  {{diff,{row,col}};
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;  // min-heap
             
        int row=height.size();
        int col=height[0].size();
    
        vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
        pq.push({0,{0,0}});

        dist[0][0]=0;
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();

            int CurrAbsDifference= front.first;
            int x=front.second.first;
            int y=front.second.second;

           if(x==row-1 && y==col-1) return CurrAbsDifference;
            
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if (newx >= 0 && newx < row && newy >= 0 && newy < col){
                       int newEffort = max(abs(height[x][y] - height[newx][newy]), CurrAbsDifference);
                    if(newEffort< dist[newx][newy]){
                        dist[newx][newy]=newEffort;
                        pq.push({newEffort,{newx,newy}});
                    }
                }
                 
                }
            }       
return 0;
        }



};
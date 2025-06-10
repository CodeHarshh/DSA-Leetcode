class Solution {
public:
    
    int findParent(int node, vector<int>& parent){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node],parent);
    }

    void unionNodes(int u, int v , vector<int>&parent , vector<int>&rank){
        int pu=findParent(u,parent);
        int pv=findParent(v,parent);

        if(pu!=pv){
            if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }
            else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }

        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
         if (connections.size() < n - 1) return -1; 

         vector<int> parent(n), rank(n,0);
        for (int i = 0; i < n; ++i) parent[i] = i;

         int components=n, redundant=0;
         for(auto it: connections){
            int u=it[0];
            int v=it[1];
             int pu = findParent(u, parent), pv = findParent(v, parent);

             if(pu==pv){
                redundant++;
             }
             else{
                unionNodes(u,v,parent,rank);
                components--;
             }
            

         }
         return (redundant>= components -1) ? components-1 : -1;
    }
};
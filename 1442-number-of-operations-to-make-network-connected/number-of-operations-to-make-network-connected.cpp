class Solution {
public:
    void dfs(vector<vector<int>> &list, vector<int> &vis, int node){
        vis[node] = 1;
        for(int i=0; i<list[node].size(); i++){
            int child = list[node][i];
            if(vis[child]==0){
               dfs(list, vis, child);
            } 
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        
        int comp = 0;
        vector<int> vis(n, 0);
        vector<vector<int>> list(n);
       
        for(int i=0; i<connections.size(); i++){
            int a  = connections[i][0];
            int b = connections[i][1];
            list[a].push_back(b);
            list[b].push_back(a);
            
        }

        for(int i=0; i<n; i++){
            if(vis[i]==0){
                comp++;
                dfs(list, vis, i);
            }
        }

        return comp-1;
    }
};
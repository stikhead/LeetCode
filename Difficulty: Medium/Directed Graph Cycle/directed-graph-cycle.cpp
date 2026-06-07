class Solution {
  public:
    bool dfs(int node, vector<vector<int>> &list, vector<int> &vis){
        vis[node] = 1;
        for(int i=0; i<list[node].size(); i++){
            if(vis[list[node][i]]==0){
                if(dfs(list[node][i], list, vis)){
                    return true;
                }
            } else if(vis[list[node][i]]==1){
                return true;
            }
        }
        vis[node] = 2;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> list(V);
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            list[a].push_back(b);
        }
        
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(vis[i]==0){
                if(dfs(i, list, vis)){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};
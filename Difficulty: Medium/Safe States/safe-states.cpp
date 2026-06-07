class Solution {
  public:
    bool dfs(vector<int> &safeNodes, vector<vector<int>> &list, vector<int> &vis, int node, int outdegree){
        vis[node] = 1;
        for(int i=0; i<list[node].size(); i++){
            int child = list[node][i];
            if(vis[child]==0){
                if(dfs(safeNodes, list, vis, child, list[child].size())) return true;
            } else if(vis[child]==1){
                return true;
            }
            outdegree--;
        }
        vis[node] = 2;
        if(outdegree==0){
            safeNodes.push_back(node);
        }
        return false;
        
    }
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<int> safe;
        vector<vector<int>> list(V);
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            list[a].push_back(b);
        }
        
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(vis[i]==0){
                dfs(safe, list, vis, i, list[i].size());
            }
        }
        return safe;
    }
};
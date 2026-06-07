class Solution {
  public:
    bool dfs(vector<vector<int>> &list, vector<int> &vis, int node, int parent){
        vis[node] = 1;
        for(int i=0; i<list[node].size(); i++){
            int child = list[node][i];
            if(child!=parent && vis[child]==0){
                if(dfs(list, vis, child, node)) return true;
            } else if(child!=parent && vis[child]==1){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int v = V;
        vector<vector<int>> list(v);
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            list[a].push_back(b);
            list[b].push_back(a);
        }
        
        queue<pair<int, int>> q;
        vector<int> vis(v, 0);
        for(int i=0; i<v; i++){
            if(vis[i]==0){
                q.push({-1, i});
                vis[i] = 1;
                while(!q.empty()){
                    auto [parent, child] = q.front();
                    q.pop();
                    for(int j=0; j<list[child].size(); j++){
                        int node = list[child][j];
                        if(node!=parent && vis[node]==0){
                            q.push({child, node});
                            vis[node] = 1;
                        } else if(node!=parent && vis[node]==1){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
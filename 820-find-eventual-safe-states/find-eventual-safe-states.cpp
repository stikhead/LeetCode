class Solution {
public:
    // bool dfs(vector<int> &safeNodes, vector<vector<int>> &list, vector<int> &vis, int node, int outdegree){
    //     vis[node] = 1;
    //     for(int i=0; i<list[node].size(); i++){
    //         int child = list[node][i];
    //         if(vis[child]==0){
    //             if(dfs(safeNodes, list, vis, child, list[child].size())) return true;
    //         } else if(vis[child]==1){
    //             return true;
    //         }
    //         outdegree--;
    //     }
    //     vis[node] = 2;
    //     if(outdegree==0){
    //         safeNodes.push_back(node);
    //     }
    //     return false;
        
    // }

    bool dfs(vector<vector<int>> &list, vector<int> &vis, int node){
        vis[node] = 1;
        for(int i=0; i<list[node].size(); i++){
            int child = list[node][i];
            if(vis[child]==0){
                if(dfs(list, vis, child)) return true;
            } else if(vis[child]==1){
                return true;
            }
        }
        vis[node] = 2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safe;
       
        int V = graph.size();
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(vis[i]==0){
                dfs(graph, vis, i);
            }
        }
        // sort(safe.begin(), safe.end());
        for(int i = 0; i < V; i++){
            if(vis[i] == 2){
                safe.push_back(i);
            }
        }
        return safe;
    }
    
};
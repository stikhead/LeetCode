class Solution {
public:
    bool dfs(int node, int destination, vector<int> &vis, vector<vector<int>> &list){
        
        if(node==destination){
            vis[node] = 1;
            return true;
        }
        vis[node] = 1;
        for(int i=0; i<list[node].size(); i++){
            if(vis[list[node][i]]==0){
                if(dfs(list[node][i], destination, vis, list)){
                    return true;
                }
            }
        }

        return false; // last node i.e nothing matched;


    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> list(n);
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            list[a].push_back(b);
            list[b].push_back(a);
        }

        vector<int> vis(n, 0);
        return dfs(source, destination, vis, list);
    }
};
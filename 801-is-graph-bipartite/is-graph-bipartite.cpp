class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int startNode, int color) {
        vis[startNode] = color;
        for (int i = 0; i < graph[startNode].size(); i++) {
            if (vis[graph[startNode][i]] == -1) {
                if(!dfs(graph, vis, graph[startNode][i], !color)){
                    return false;
                } 

            } else if(vis[graph[startNode][i]]==color){
                    return false;
                }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            if(vis[i]==-1) {
                if(!dfs(graph, vis, i, 0)){
                    return false;
                }
            }
        }

        return true;
    }
};
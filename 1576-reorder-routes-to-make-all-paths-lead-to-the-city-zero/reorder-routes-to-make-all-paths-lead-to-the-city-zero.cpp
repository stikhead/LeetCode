class Solution {
public:
    int dfs(vector<vector<pair<int, int>>> &list, int node, vector<int> &vis){
        vis[node] = 1;
        int count = 0;
        for(int i=0; i<list[node].size(); i++){
            if(vis[list[node][i].first]==0){
                count += list[node][i].second + dfs(list, list[node][i].first, vis);
            }
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> list(n);
        for(int i=0; i<connections.size(); i++){
            int a = connections[i][0];
            int b = connections[i][1];
            list[a].push_back({b, 1});
            list[b].push_back({a, 0});
        }
        int count = 0;
        vector<int> vis(n, 0);
        for(int i=0; i<vis.size(); i++){
            if(vis[i]==0){
                count+=dfs(list, i, vis);
            }
        }
        return count;
    }
};
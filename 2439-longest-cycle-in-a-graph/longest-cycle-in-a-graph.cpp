class Solution {
public:
    int countLength(vector<vector<int>> &list, int node, vector<int> &vis){
        int count = 0;
        if(vis[node]==1){
            vis[node] = 3;
            count += 1 + countLength(list, list[node][0], vis);
        }
        return count;
    }
    int dfs(vector<vector<int>> &list, int node, vector<int> &vis){
        vis[node] = 1;
        int count = 0;
        if(list[node].size()>0){
            int child = list[node][0];
            if(vis[child]==0){
                count+=dfs(list, child, vis);
            } else if(vis[child]==1){
                count+= countLength(list, child, vis);
            }
        }
        vis[node] = 2;
        return count;
    }
    int longestCycle(vector<int>& edges) {
        int count = 0;
        vector<int> vis(edges.size(), 0);
        vector<vector<int>> list(edges.size());
        for(int i=0; i<edges.size(); i++){
            if(edges[i]>=0){
                list[i].push_back(edges[i]);
            }    
        }

        for(int i=0; i<edges.size(); i++){
            if(vis[i]==0){
                count = max(count, dfs(list, i, vis));
            }
        }
        return count==0 ? -1 : count; 
    }
};
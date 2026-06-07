class Solution {
public:

    bool dfs(vector<vector<int>> &list, vector<int> &vis, vector<int> &ans, int node){
        vis[node] = 1;
        for(int i=0; i<list[node].size(); i++){
            int child = list[node][i];
            if(vis[child]==0){
                if(dfs(list, vis, ans, child)){
                    return true;
                }
            } else if(vis[child]==1){
                return true;
            }
        }
        vis[node] = 2;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> list(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            list[b].push_back(a);
        }

        vector<int> vis(numCourses, 0);
        // vector<int> indegrees(numCourses);
        // for(int i=0; i<numCourses; i++){
        //     for(int j=0; j<list[i].size(); j++){
        //         indegree[list[i][j]]++;
        //     }
        // }
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(vis[i]==0){
                if(dfs(list, vis, ans, i)){
                    return {};
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
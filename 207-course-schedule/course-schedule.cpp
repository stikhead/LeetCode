class Solution {
public:

    bool dfs(vector<vector<int>> &adjList, vector<int> &vis, int node){
        if(vis[node]==1){
            return true;
        }
        if(vis[node]==2){
            return false;
        }
        vis[node] = 1;
        for(int i=0; i<adjList[node].size(); i++){
            if(dfs(adjList, vis, adjList[node][i])){
                return true;
            }
        }
        vis[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> vis(numCourses, 0);
     
        for(int i=0; i<numCourses; i++){
            if(dfs(adjList, vis, i)){
                return false;
            }
        }

        return true;


    }
};
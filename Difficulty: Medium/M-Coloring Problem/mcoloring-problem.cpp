class Solution {
  public:
  
    bool isColorable(int node, vector<vector<int>> &adjList, int c, vector<int> &visited){
        for(int i=0; i<adjList[node].size(); i++){
            if(visited[adjList[node][i]]==c){
                return false;
            }
        }
        return true;
    }
    bool recursion(vector<vector<int>> &adjList, int node, int m, vector<int> &visited){
        if(node==adjList.size()){
            return true;
        }
        
        for(int i=1; i<=m; i++){
            if(isColorable(node, adjList, i, visited)){
                visited[node] = i;
                if(recursion(adjList, node+1, m, visited)){
                    return true;
                }
                visited[node] = 0;
            }
        }
        
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adjList(v);
        for(int i=0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> visited(v, 0);
        
        return recursion(adjList, 0, m , visited);
        
        
    }
};
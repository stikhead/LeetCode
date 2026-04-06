class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (source == destination) {
            return true;
        }
        vector<vector<int>> adjList(n);
        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> q;
        vector<int> visited(n, 0);
        q.push(source);
        visited[source] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < adjList[node].size(); i++) {
                if (adjList[node][i] == destination) { // early return or do return visited[destination] == 1 at end
                    return true; 
                } else if (!visited[adjList[node][i]]) {
                    visited[adjList[node][i]] = 1;
                    q.push(adjList[node][i]);
                }
            }
        }
        return false; 
    }
};
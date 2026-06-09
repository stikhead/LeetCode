// User function Template for C++
class Solution {
	public:
	vector<int> shortestPath(int V, int E, vector<vector<int>> & edges) {
		vector<vector<pair<int, int>> > list(V);
		for (int i = 0; i<edges.size(); i++) {
			int a = edges[i][0];
			int b = edges[i][1];
			int w = edges[i][2];
			list[a].push_back({b, w});
		}
		
		vector<int> vis(V, INT_MAX);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
		q.push({0, 0});
		vis[0] = 0;
		while (!q.empty()) {
			int dist = q.top().first;
			int node = q.top().second;
			q.pop();
			
			if (dist > vis[node])
				continue;
			for (int i = 0; i<list[node].size(); i++) {
				int child = list[node][i].first;
				int childWeight = list[node][i].second;
				
				if (vis[node] + childWeight < vis[child]) {
					vis[child] = vis[node] + childWeight;
					q.push({vis[child], child});
				}
				
			}
		}
		
		for(int i=0; i<V; i++){
		    if(vis[i]==INT_MAX){
		        vis[i] = -1;
		    }
		}
		return vis;
	}
};

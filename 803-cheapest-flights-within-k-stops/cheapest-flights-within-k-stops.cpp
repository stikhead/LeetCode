class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> list(n);
        for (int i = 0; i < flights.size(); i++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int cost = flights[i][2];
            list[from].push_back({to, cost});
        }

        vector<int> vis(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vis[src] = 0;
        while (!q.empty()) {

            auto [flight, nodes] = q.front();
            auto [node, cost] = nodes;
            q.pop();

            if (flight > k)
                continue;

            for (int j = 0; j < list[node].size(); j++) {
                int child = list[node][j].first;
                if (vis[child] > list[node][j].second + cost && flight <= k) {
                    vis[child] = list[node][j].second + cost;
                    q.push({flight + 1, {child, vis[child]}});
                }

                // if(child==dst && k==level) return vis[child];
            }
        }
        return vis[dst] == INT_MAX ? -1 : vis[dst];
    }
};
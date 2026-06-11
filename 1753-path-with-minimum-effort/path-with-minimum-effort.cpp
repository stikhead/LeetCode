class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        if (n == 1 && m == 1)
            return 0;

        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            q;
        q.push({0, 0, 0});
        vis[0][0] = 0;
        while (!q.empty()) {
            auto node = q.top();
            int row = node[1], col = node[2], cost = node[0];
            q.pop();

            if (row == n - 1 && col == m - 1)
                return cost;
            if (cost > vis[row][col])
                continue;
            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i].first;
                int ncol = col + dir[i].second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    // cout << nrow << " " << ncol << endl;
                    if (abs(heights[nrow][ncol] - heights[row][col]) <
                        vis[nrow][ncol]) {
                        int currentEffort =
                            abs(heights[row][col] - heights[nrow][ncol]);
                        int pathEffort = max(cost, currentEffort);

                        if (pathEffort < vis[nrow][ncol]) {
                            vis[nrow][ncol] = pathEffort;
                            q.push({pathEffort, nrow, ncol});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
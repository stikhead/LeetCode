class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }
        
        if (n == 1) return 1;
        
        queue<pair<pair<int, int>, int>> q;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0},   {0, -1}, {-1, 0},
                                      {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

        q.push({{0, 0}, 1});
        grid[0][0] = 1;
        while (!q.empty()) {
            auto [coords, step] = q.front();
            auto [row, col] = coords;
            q.pop();

            if (row == n - 1 && col == n - 1)
                return step;

            for (int i = 0; i < 8; i++) {
                int nrow = row + dir[i].first;
                int ncol = col + dir[i].second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0) {
                    if (nrow == n - 1 && ncol == n - 1) {
                        return step + 1;
                    }
                    q.push({{nrow, ncol}, step + 1});
                    grid[nrow][ncol] = 1;
                }
            }
        }
        return -1;
    }
};
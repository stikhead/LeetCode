class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> output(m, vector<int>(n, 0));
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } 
                if(mat[i][j]==1){
                    output[i][j] = -1;
                }
            }
        }
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {

                int nrow = row + dir[j].first;
                int ncol = col + dir[j].second;

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    if(output[nrow][ncol] == -1) {
                        output[nrow][ncol] = output[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return output;
    }
};
class Solution {
public:
    void bfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j) {
        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;


        q.push({i, j});
        vis[i][j] = 1;
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i].first;
                int ncol = col + dir[i].second;

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    if (board[nrow][ncol] == 'O' && vis[nrow][ncol]==0) {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' &&  vis[i][0]==0) {
                bfs(board, vis, i, 0);
            }
            if (board[i][n-1] == 'O'  && vis[i][n-1]==0) {
                bfs(board, vis, i, n-1);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O'  && vis[0][i]==0) {
                bfs(board, vis, 0, i);
            }
            if (board[m-1][i] == 'O'  && vis[m-1][i]==0) {
                bfs(board, vis, m-1, i);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
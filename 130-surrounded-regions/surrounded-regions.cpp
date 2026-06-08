class Solution {
public:
    void bfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;


        q.push({i, j});
        board[i][j] = '#';
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i].first;
                int ncol = col + dir[i].second;

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    if (board[nrow][ncol] == 'O') {
                        board[nrow][ncol] = '#';
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                bfs(board, i, 0);
            }
            if (board[i][n-1] == 'O') {
                bfs(board, i, n-1);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                bfs(board, 0, i);
            }
            if (board[m-1][i] == 'O') {
                bfs(board, m-1, i);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j]=='#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
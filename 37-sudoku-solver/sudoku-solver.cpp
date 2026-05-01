class Solution {
public:
    bool isAvailable(vector<vector<char>>& board, int r, int c, char k) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == k)
                return false;

            if (board[i][c] == k)
                return false;

            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == k)
                return false;
        }

        return true;
    }
    bool recursion(vector<vector<char>>& board, int r, int c) {
        if (r == 9) {
            return true;
        }

        int nextR = (c == 8) ? r + 1 : r;
        int nextC = (c == 8) ? 0 : c + 1;

        if (board[r][c] != '.') {
            return recursion(board, nextR, nextC);
        }

        if (board[r][c] == '.') {
            for (char k = '1'; k <= '9'; k++) {

                if (isAvailable(board, r, c, k)) {
                    board[r][c] = k;
                    bool flag = recursion(board, nextR, nextC);
                    if (flag) {
                        return true;
                    }
                    board[r][c] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> temp = board;
        if (recursion(board, 0, 0)) {
            return;
        }
    };
};
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
    bool recursion(vector<vector<char>>& temp, vector<vector<char>>& board,
                   int r, int c) {
        if (r == 9 && c == 0) {
            board = temp;
            return true;
        }
        
        if (r < 9 && c < 9 && temp[r][c] != '.') {
            if (c + 1 == 9) {
                bool flag = recursion(temp, board, r + 1, (c + 1) % 9);
                if (flag) {
                    return true;
                }
            } else {
                bool flag = recursion(temp, board, r, c + 1);
                if (flag) {
                    return true;
                }
            }
        }
        if (r < 9 && c < 9 && temp[r][c] == '.') {
            for (char k = '1'; k <= '9'; k++) {

                if (isAvailable(temp, r, c, k)) {
                    temp[r][c] = k;
                    if (c + 1 == 9) {
                        bool flag = recursion(temp, board, r + 1, (c + 1) % 9);
                        if (flag) {
                            return true;
                        }
                    } else {
                        bool flag = recursion(temp, board, r, c + 1);
                        if (flag) {
                            return true;
                        }
                    }
                    temp[r][c] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> temp = board;
        if (recursion(temp, board, 0, 0)) {
            return;
        };
    }
};
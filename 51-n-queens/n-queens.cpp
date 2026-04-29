class Solution {
public:
    void recursion(vector<vector<char>>& board, vector<vector<string>>& ans, int row, int col, int n, int queens) {
        if (queens == n) {
            vector<string> row = {};
            string s = "";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    s.push_back(board[i][j]);
                }
                row.push_back(s);
                s="";
            }
            ans.push_back(row);
            return;
        }

        if (row >= n) return;

        int tempRow = row;
        int tempCol = col - 1;
        while (tempRow >= 0 && tempRow<n && tempCol >= 0) {
            if (board[tempRow][tempCol] == 'Q') {
                
                recursion(board, ans, row+1, col, n, queens);
                return;
            }
            tempCol--;
        }

        tempRow = row - 1;
        tempCol = col - 1;
        while (tempRow >= 0 && tempRow<n && tempCol >= 0) {
            if (board[tempRow][tempCol] == 'Q') {
                
                recursion(board, ans, row+1, col, n, queens);
                return;
            }
            tempRow--;
            tempCol--;
        }

        tempRow = row + 1;
        tempCol = col - 1;
        while (tempRow >= 0 && tempRow < n && tempCol >= 0) {
            if (board[tempRow][tempCol] == 'Q') {
                recursion(board, ans, row+1, col, n, queens);
                return;
            }
            tempRow++;
            tempCol--;
        }
        
            if (row >= 0 && row < n && col >= 0 && col < n) {
                queens++;
                board[row][col] = 'Q';
                recursion(board, ans, 0, col + 1, n, queens);
                board[row][col] = '.';
                queens--;
            
        }

        recursion(board, ans, row + 1, col, n, queens);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans = {};
        int queens = 0;
        for (int i = 0; i < n; i++) {
            queens++;
            board[i][0] = 'Q';
            recursion(board, ans, 0, 1, n, queens);
            board[i][0] = '.';
            queens--;
        }

        return ans;
    }
};
class Solution {
public:
    bool recursion(vector<vector<char>>& board, vector<vector<int>>& visited,
                   string word, int r, int c, int index, string& output) {
        if (output == word) {
            return true;
        }

        if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size()) {
            if (!visited[r][c] && index < word.size() &&
                word[index] == board[r][c]) {
                output.push_back(board[r][c]);
                visited[r][c] = 1;
                index += 1;
                bool found =  recursion(board, visited, word, r, c + 1, index, output) ||
                              recursion(board, visited, word, r, c - 1, index, output) ||
                              recursion(board, visited, word, r + 1, c, index, output) ||
                              recursion(board, visited, word, r - 1, c, index, output);
                if(found){
                    return true;
                }
                index--;
                output.pop_back();
                visited[r][c] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        string output = "";
        string ans = "";
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    if(recursion(board, visited, word, i, j, 0, output)){
                        return true;
                    }
                    ans = "";
                }
            }
        }
        return false;
    }
};
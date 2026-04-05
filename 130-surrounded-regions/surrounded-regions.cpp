class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> val(m, vector<bool>(n, false));
        vector<pair<int, int>> dir = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            if(board[0][i]=='O'){
                q.push({0, i});
                val[0][i] = true;
            } 
             if(m>1&&board[m-1][i]=='O'){
                q.push({m-1, i});
                val[m-1][i] = true;
            } 
        }
        for(int i=0; i<m; i++){
            if(board[i][0]=='O'){
                q.push({i, 0});
                val[i][0] = true;
            } 
             if(n>1 && board[i][n-1]=='O'){
                q.push({i, n-1});
                val[i][n-1] = true;
            }
        }

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row + dir[i].first;
                int ncol = col + dir[i].second;
                if(nrow>=0 && ncol >=0 && nrow<m && ncol <n){
                    if(board[nrow][ncol] == 'O' && !val[nrow][ncol]){
                        val[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(!val[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
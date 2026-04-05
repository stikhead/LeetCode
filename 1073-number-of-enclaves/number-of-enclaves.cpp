class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> val(m, vector<int>(n, -1));
        vector<pair<int, int>> dir = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            if(grid[0][i]==1 && val[0][i] == -1){
                q.push({0, i});
                val[0][i] = 0;
            } 
             if(m>1&&grid[m-1][i]==1 && val[m-1][i] == -1){
                q.push({m-1, i});
                val[m-1][i] = 0;
            } 
        }
        for(int i=0; i<m; i++){
            if(grid[i][0]==1 && val[i][0] == -1){
                q.push({i, 0});
                val[i][0] = 0;
            } 
             if(n>1 && grid[i][n-1]==1 && val[i][n-1] == -1){
                q.push({i, n-1});
                val[i][n-1] = 0;
            }
        }

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row + dir[i].first;
                int ncol = col + dir[i].second;
                if(nrow>=0 && ncol >=0 && nrow<m && ncol <n){
                    if(grid[nrow][ncol] == 1 && val[nrow][ncol]==-1){
                        val[nrow][ncol] = 0;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        int count = 0;
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(val[i][j]==-1 && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};